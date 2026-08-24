#pragma once

#include <Arduino.h>

enum WheelIndex : uint8_t {
  WHEEL_FL = 0,
  WHEEL_FR = 1,
  WHEEL_RL = 2,
  WHEEL_RR = 3,
  WHEEL_COUNT = 4
};

const uint8_t MOTOR_PWM_PIN[WHEEL_COUNT] = { 9, 10, 11, 3 };
const uint8_t MOTOR_IN1_PIN[WHEEL_COUNT] = { 7, 12, A0, A2 };
const uint8_t MOTOR_IN2_PIN[WHEEL_COUNT] = { 8, 13, A1, A3 };

const uint8_t MOTOR_MIN_PWM = 40;
const uint8_t MOTOR_MAX_PWM = 255;

const uint8_t ENCODER_A_PIN[WHEEL_COUNT] = { 2, 4, 5, 6 };

const float COUNTS_PER_REV = 330.0f;

const float WHEEL_RADIUS = 0.040f;
const float WHEEL_BASE_X = 0.100f;
const float WHEEL_BASE_Y = 0.110f;

const float MAX_LINEAR_VEL  = 0.60f;
const float MAX_ANGULAR_VEL = 3.00f;

const uint16_t CONTROL_PERIOD_MS   = 20;
const uint16_t TELEMETRY_PERIOD_MS = 50;

const uint16_t COMMAND_TIMEOUT_MS = 500;

const float PID_KP = 6.0f;
const float PID_KI = 12.0f;
const float PID_KD = 0.0f;

const float PID_I_LIMIT = 120.0f;

const float PID_FEEDFORWARD = 14.0f;

const uint32_t SERIAL_BAUD = 115200;
const uint8_t  SERIAL_RX_BUFFER = 64;
