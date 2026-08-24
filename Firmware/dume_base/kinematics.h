#pragma once

#include <Arduino.h>
#include "config.h"

namespace kinematics {

void inverse(float vx, float vy, float wz, float* out);

void forward(const float* wheelVel, float* vx, float* vy, float* wz);

void clampCommand(float* vx, float* vy, float* wz);

}
