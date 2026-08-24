#pragma once

#include <Arduino.h>
#include "config.h"

namespace motors {

void begin();

void setWheel(uint8_t wheel, int16_t duty);

void coast(uint8_t wheel);

void stopAll();

void setInverted(uint8_t wheel, bool inverted);

}
