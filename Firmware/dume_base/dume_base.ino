#include <Arduino.h>
#include "config.h"
#include "encoders.h"
#include "motors.h"
#include "kinematics.h"
#include "pid.h"

static VelocityPid s_pid[WHEEL_COUNT];
static float s_targetWheelVel[WHEEL_COUNT];
static float s_measWheelVel[WHEEL_COUNT];

static float s_cmdVx = 0.0f, s_cmdVy = 0.0f, s_cmdWz = 0.0f;

static float s_poseX = 0.0f, s_poseY = 0.0f, s_poseTheta = 0.0f;
static float s_bodyVx = 0.0f, s_bodyVy = 0.0f, s_bodyWz = 0.0f;

static uint32_t s_lastControlMs = 0;
static uint32_t s_lastTelemetryMs = 0;
static uint32_t s_lastCommandMs = 0;

static bool s_openLoop = false;
static int16_t s_openLoopDuty[WHEEL_COUNT];

static char s_rxBuf[SERIAL_RX_BUFFER];
static uint8_t s_rxLen = 0;

static void applyStop() {
  s_cmdVx = s_cmdVy = s_cmdWz = 0.0f;
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    s_targetWheelVel[i] = 0.0f;
    s_openLoopDuty[i] = 0;
    s_pid[i].reset();
  }
  motors::stopAll();
}

static void handleLine(char* line) {
  char* tok = strtok(line, " \t");
  if (tok == NULL) return;

  switch (tok[0]) {
    case 'V': {
      char* sx = strtok(NULL, " \t");
      char* sy = strtok(NULL, " \t");
      char* sw = strtok(NULL, " \t");
      if (!sx || !sy || !sw) {
        Serial.println(F("ERR V needs 3 args"));
        return;
      }
      s_cmdVx = atof(sx);
      s_cmdVy = atof(sy);
      s_cmdWz = atof(sw);
      kinematics::clampCommand(&s_cmdVx, &s_cmdVy, &s_cmdWz);
      kinematics::inverse(s_cmdVx, s_cmdVy, s_cmdWz, s_targetWheelVel);
      s_openLoop = false;
      s_lastCommandMs = millis();
      break;
    }

    case 'S':
      applyStop();
      s_lastCommandMs = millis();
      break;

    case 'R':
      s_poseX = s_poseY = s_poseTheta = 0.0f;
      encoders::resetTotals();
      s_lastCommandMs = millis();
      break;

    case 'M': {
      char* sw = strtok(NULL, " \t");
      char* sd = strtok(NULL, " \t");
      if (!sw || !sd) {
        Serial.println(F("ERR M needs 2 args"));
        return;
      }
      const int wheel = atoi(sw);
      if (wheel < 0 || wheel >= WHEEL_COUNT) {
        Serial.println(F("ERR wheel out of range"));
        return;
      }
      s_openLoop = true;
      s_openLoopDuty[wheel] = (int16_t)atoi(sd);
      s_lastCommandMs = millis();
      break;
    }

    case 'C':
      s_openLoop = false;
      for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
        s_openLoopDuty[i] = 0;
        s_pid[i].reset();
      }
      s_lastCommandMs = millis();
      break;

    case 'I': {
      char* sw = strtok(NULL, " \t");
      char* sv = strtok(NULL, " \t");
      if (!sw || !sv) {
        Serial.println(F("ERR I needs 2 args"));
        return;
      }
      const int wheel = atoi(sw);
      if (wheel < 0 || wheel >= WHEEL_COUNT) {
        Serial.println(F("ERR wheel out of range"));
        return;
      }
      motors::setInverted((uint8_t)wheel, atoi(sv) != 0);
      s_lastCommandMs = millis();
      break;
    }

    case 'P':
      Serial.println(F("PONG"));
      s_lastCommandMs = millis();
      break;

    default:
      Serial.println(F("ERR unknown command"));
      break;
  }
}

static void pollSerial() {
  while (Serial.available() > 0) {
    const char c = (char)Serial.read();

    if (c == '\n' || c == '\r') {
      if (s_rxLen > 0) {
        s_rxBuf[s_rxLen] = '\0';
        handleLine(s_rxBuf);
        s_rxLen = 0;
      }
      continue;
    }

    if (s_rxLen < SERIAL_RX_BUFFER - 1) {
      s_rxBuf[s_rxLen++] = c;
    } else {
      s_rxLen = 0;
      Serial.println(F("ERR line too long"));
    }
  }
}

static void runControl(float dt) {
  int32_t delta[WHEEL_COUNT];
  encoders::readAndResetDelta(delta);

  const float radPerCount = TWO_PI / COUNTS_PER_REV;
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    s_measWheelVel[i] = ((float)delta[i] * radPerCount) / dt;
  }

  kinematics::forward(s_measWheelVel, &s_bodyVx, &s_bodyVy, &s_bodyWz);
  const float midTheta = s_poseTheta + s_bodyWz * dt * 0.5f;
  s_poseX += (s_bodyVx * cos(midTheta) - s_bodyVy * sin(midTheta)) * dt;
  s_poseY += (s_bodyVx * sin(midTheta) + s_bodyVy * cos(midTheta)) * dt;
  s_poseTheta += s_bodyWz * dt;

  while (s_poseTheta >  PI) s_poseTheta -= TWO_PI;
  while (s_poseTheta <= -PI) s_poseTheta += TWO_PI;

  if (s_openLoop) {
    for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
      motors::setWheel(i, s_openLoopDuty[i]);
    }
    return;
  }

  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    const int16_t duty = s_pid[i].update(s_targetWheelVel[i], s_measWheelVel[i], dt);
    motors::setWheel(i, duty);
  }
}

static void sendTelemetry() {
  int32_t totals[WHEEL_COUNT];
  encoders::readTotals(totals);

  Serial.print(F("O "));
  Serial.print(s_poseX, 4);     Serial.print(' ');
  Serial.print(s_poseY, 4);     Serial.print(' ');
  Serial.print(s_poseTheta, 4); Serial.print(' ');
  Serial.print(s_bodyVx, 3);    Serial.print(' ');
  Serial.print(s_bodyVy, 3);    Serial.print(' ');
  Serial.print(s_bodyWz, 3);
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    Serial.print(' ');
    Serial.print(totals[i]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(SERIAL_BAUD);

  motors::begin();
  encoders::begin();
  applyStop();

  const uint32_t now = millis();
  s_lastControlMs = now;
  s_lastTelemetryMs = now;
  s_lastCommandMs = now - COMMAND_TIMEOUT_MS;

  Serial.println(F("BOOT"));
}

void loop() {
  pollSerial();

  const uint32_t now = millis();

  if (now - s_lastCommandMs > COMMAND_TIMEOUT_MS) {
    if (s_cmdVx != 0.0f || s_cmdVy != 0.0f || s_cmdWz != 0.0f || s_openLoop) {
      applyStop();
      s_openLoop = false;
    }
  }

  if (now - s_lastControlMs >= CONTROL_PERIOD_MS) {
    const float dt = (float)(now - s_lastControlMs) * 0.001f;
    s_lastControlMs = now;
    runControl(dt);
  }

  if (now - s_lastTelemetryMs >= TELEMETRY_PERIOD_MS) {
    s_lastTelemetryMs = now;
    sendTelemetry();
  }
}
