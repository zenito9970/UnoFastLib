# UnoFastLib
Library to do replace with constant expression at compile time for Arduino UNO (ATmega328P) C++14 compiler

## Usage

**!!Warning!!**  
I only checked the operation with Arduino IDE 1.8.7 on Windows 10.

1. Enable C++14 compilation: Rewrite `-std=gnu++11` of `compiler.cpp.flags` in `Program Files (x86)/Arduino/hardware/arduino/avr/platform.txt` to `-std=c++14`.
1. `$ git clone https://github.com/zenito9970/UnoFastLib.git` in the project directory.
1. Add `#include "UnoFastLib/UnoFastLib.hpp"` at the beginning of the source code.

## Methods

### digitalWriteFast(pin, val)

The operation is the same as `digitalWrite(pin, val)`.  
Both `pin` and `val` must be constant values.

### digitalReadFast(pin)

The operation is the same as `digitalRead(pin)`.  
`pin` must be a constant value.

