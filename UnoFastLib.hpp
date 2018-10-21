#ifndef _UNO_FAST_LIB_HPP_
#define _UNO_FAST_LIB_HPP_

#include <Arduino.h>

namespace UnoFastLib {

static constexpr uint8_t PB = 0;
static constexpr uint8_t PC = 1;
static constexpr uint8_t PD = 2;

static constexpr uint8_t dpin2port[] = {
  PD, PD, PD, PD, PD, PD, PD, PD, // 0~7
  PB, PB, PB, PB, PB, PB,         // 8~13
  PC, PC, PC, PC, PC, PC          // 14~19
};

static constexpr uint8_t dpin2mask[] = {
  _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7),
  _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5),
  _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5)
};

template <uint8_t port>
static constexpr volatile uint8_t *portOutRegX() {
  static_assert(port == PB || port == PC || port == PD, "invalid port number");
  return (port == PB ? &PORTB : 
         (port == PC ? &PORTC : 
         (port == PD ? &PORTD : NULL)));
}

template <uint8_t port>
static constexpr volatile uint8_t *portInRegX() {
  static_assert(port == PB || port == PC || port == PD, "invalid port number");
  return (port == PB ? &PINB : 
         (port == PC ? &PINC : 
         (port == PD ? &PIND : NULL)));
}

template <uint16_t pin>
static constexpr uint8_t dpin2maskX() {
  static_assert(pin < sizeof(dpin2mask), "invalid pin number");
  return dpin2mask[pin];
}

template <uint16_t pin>
static constexpr uint8_t dpin2portX() {
  static_assert(pin < sizeof(dpin2port), "invalid pin number");
  return dpin2port[pin];
}

template <uint16_t pin, uint8_t val>
static inline void dwriteF_() {
  constexpr uint8_t mask = dpin2maskX<pin>();
  constexpr uint8_t port = dpin2portX<pin>();
  constexpr volatile uint8_t *out = portOutRegX<port>();
  *out = val ? (*out | mask) : (*out & ~mask);
}

template <uint16_t pin>
static inline uint8_t dreadF_() {
  constexpr uint8_t mask = dpin2maskX<pin>();
  constexpr uint8_t port = dpin2portX<pin>();
  constexpr volatile uint8_t *in = portInRegX<port>();
  return (*in & mask) ? HIGH : LOW;
}

} // namespace

#define digitalWriteFast(pin, val) do{UnoFastLib::dwriteF_<pin, val>()}while(0)
#define digitalReadFast(pin) (UnoFastLib::dreadF_<pin>())

#endif
