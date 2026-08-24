#include "encoders.h"

static const uint8_t kPortDMask[WHEEL_COUNT] = {
  _BV(PD2), _BV(PD4), _BV(PD5), _BV(PD6)
};

static volatile int32_t s_delta[WHEEL_COUNT];
static volatile int32_t s_total[WHEEL_COUNT];
static volatile int8_t  s_dir[WHEEL_COUNT];
static volatile uint8_t s_prevPortD;

namespace encoders {

void begin() {
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    pinMode(ENCODER_A_PIN[i], INPUT_PULLUP);
    s_delta[i] = 0;
    s_total[i] = 0;
    s_dir[i] = 1;
  }

  s_prevPortD = PIND;

  PCICR |= _BV(PCIE2);
  PCMSK2 |= _BV(PCINT18) | _BV(PCINT20) | _BV(PCINT21) | _BV(PCINT22);
}

void setAssumedDirection(uint8_t wheel, int8_t dir) {
  if (wheel >= WHEEL_COUNT) return;
  s_dir[wheel] = dir;
}

void readCounts(int32_t* dest) {
  const uint8_t sreg = SREG;
  cli();
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) dest[i] = s_delta[i];
  SREG = sreg;
}

void readAndResetDelta(int32_t* dest) {
  const uint8_t sreg = SREG;
  cli();
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    dest[i] = s_delta[i];
    s_delta[i] = 0;
  }
  SREG = sreg;
}

void readTotals(int32_t* dest) {
  const uint8_t sreg = SREG;
  cli();
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) dest[i] = s_total[i];
  SREG = sreg;
}

void resetTotals() {
  const uint8_t sreg = SREG;
  cli();
  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) s_total[i] = 0;
  SREG = sreg;
}

}

ISR(PCINT2_vect) {
  const uint8_t now = PIND;
  const uint8_t changed = now ^ s_prevPortD;
  s_prevPortD = now;

  const uint8_t rising = changed & now;

  for (uint8_t i = 0; i < WHEEL_COUNT; ++i) {
    if (rising & kPortDMask[i]) {
      s_delta[i] += s_dir[i];
      s_total[i] += s_dir[i];
    }
  }
}
