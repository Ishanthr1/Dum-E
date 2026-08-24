#include "motors.h"
#include "encoders.h"

static bool s_inverted[WHEEL_COUNT];

namespace motors {

void begin() {
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    pinMode(MOTOR_PWM_PIN[i], OUTPUT);
    pinMode(MOTOR_IN1_PIN[i], OUTPUT);
    pinMode(MOTOR_IN2_PIN[i], OUTPUT);
    s_inverted[i] = false;
    coast(i);
  }
}

void setInverted(uint8_t wheel, bool inverted) {
  if (wheel >= WHEEL_COUNT) return;
  s_inverted[wheel] = inverted;
}

void coast(uint8_t wheel) {
  if (wheel >= WHEEL_COUNT) return;
  analogWrite(MOTOR_PWM_PIN[wheel], 0);
  digitalWrite(MOTOR_IN1_PIN[wheel], LOW);
  digitalWrite(MOTOR_IN2_PIN[wheel], LOW);
}

void setWheel(uint8_t wheel, int16_t duty) {
  if (wheel >= WHEEL_COUNT) return;

  if (s_inverted[wheel]) duty = -duty;

  const int8_t dir = (duty >= 0) ? 1 : -1;
  encoders::setAssumedDirection(wheel, dir);

  uint16_t magnitude = (duty >= 0) ? (uint16_t)duty : (uint16_t)(-duty);
  if (magnitude > MOTOR_MAX_PWM) magnitude = MOTOR_MAX_PWM;

  if (magnitude < MOTOR_MIN_PWM) {
    coast(wheel);
    return;
  }

  if (dir > 0) {
    digitalWrite(MOTOR_IN1_PIN[wheel], HIGH);
    digitalWrite(MOTOR_IN2_PIN[wheel], LOW);
  } else {
    digitalWrite(MOTOR_IN1_PIN[wheel], LOW);
    digitalWrite(MOTOR_IN2_PIN[wheel], HIGH);
  }
  analogWrite(MOTOR_PWM_PIN[wheel], (uint8_t)magnitude);
}

void stopAll() {
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) coast(i);
}

}
