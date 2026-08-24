#pragma once

#include <Arduino.h>
#include "config.h"

class VelocityPid {
 public:
  VelocityPid() : integral_(0.0f), prevError_(0.0f) {}

  void reset() {
    integral_ = 0.0f;
    prevError_ = 0.0f;
  }

  int16_t update(float setpoint, float measured, float dt) {
    if (dt <= 0.0f) return 0;

    const float error = setpoint - measured;

    float output = PID_FEEDFORWARD * setpoint + PID_KP * error;

    integral_ += error * dt;
    if (integral_ >  PID_I_LIMIT / (PID_KI > 0.0f ? PID_KI : 1.0f))
      integral_ =  PID_I_LIMIT / (PID_KI > 0.0f ? PID_KI : 1.0f);
    if (integral_ < -PID_I_LIMIT / (PID_KI > 0.0f ? PID_KI : 1.0f))
      integral_ = -PID_I_LIMIT / (PID_KI > 0.0f ? PID_KI : 1.0f);
    output += PID_KI * integral_;

    if (PID_KD > 0.0f) {
      output += PID_KD * (error - prevError_) / dt;
    }
    prevError_ = error;

    if (setpoint == 0.0f) {
      integral_ *= 0.5f;
      if (fabs(measured) < 0.05f) {
        integral_ = 0.0f;
        return 0;
      }
    }

    if (output >  (float)MOTOR_MAX_PWM) output =  (float)MOTOR_MAX_PWM;
    if (output < -(float)MOTOR_MAX_PWM) output = -(float)MOTOR_MAX_PWM;
    return (int16_t)output;
  }

 private:
  float integral_;
  float prevError_;
};
