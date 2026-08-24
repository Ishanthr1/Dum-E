#pragma once

#include <Arduino.h>
#include "config.h"

namespace encoders {

void begin();

void readCounts(int32_t* dest);

void readAndResetDelta(int32_t* dest);

void resetTotals();

void readTotals(int32_t* dest);

void setAssumedDirection(uint8_t wheel, int8_t dir);

}
