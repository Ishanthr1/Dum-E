#include "kinematics.h"

static const float kLxPlusLy = WHEEL_BASE_X + WHEEL_BASE_Y;

namespace kinematics {

void inverse(float vx, float vy, float wz, float* out) {
  const float invR = 1.0f / WHEEL_RADIUS;
  const float yaw = kLxPlusLy * wz;

  out[WHEEL_FL] = invR * (vx - vy - yaw);
  out[WHEEL_FR] = invR * (vx + vy + yaw);
  out[WHEEL_RL] = invR * (vx + vy - yaw);
  out[WHEEL_RR] = invR * (vx - vy + yaw);
}

void forward(const float* w, float* vx, float* vy, float* wz) {
  const float r4 = WHEEL_RADIUS * 0.25f;

  *vx = r4 * ( w[WHEEL_FL] + w[WHEEL_FR] + w[WHEEL_RL] + w[WHEEL_RR]);
  *vy = r4 * (-w[WHEEL_FL] + w[WHEEL_FR] + w[WHEEL_RL] - w[WHEEL_RR]);
  *wz = (WHEEL_RADIUS / (4.0f * kLxPlusLy)) *
        (-w[WHEEL_FL] + w[WHEEL_FR] - w[WHEEL_RL] + w[WHEEL_RR]);
}

void clampCommand(float* vx, float* vy, float* wz) {
  if (*vx >  MAX_LINEAR_VEL) *vx =  MAX_LINEAR_VEL;
  if (*vx < -MAX_LINEAR_VEL) *vx = -MAX_LINEAR_VEL;
  if (*vy >  MAX_LINEAR_VEL) *vy =  MAX_LINEAR_VEL;
  if (*vy < -MAX_LINEAR_VEL) *vy = -MAX_LINEAR_VEL;
  if (*wz >  MAX_ANGULAR_VEL) *wz =  MAX_ANGULAR_VEL;
  if (*wz < -MAX_ANGULAR_VEL) *wz = -MAX_ANGULAR_VEL;
}

}
