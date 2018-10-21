# UnoFastLib
Library to do replace with constant expression at compile time for Arduino UNO (ATmega328P) C++14 compiler

## Methods

### digitalWriteFast(pin, val)

The operation is the same as `digitalWrite(pin, val)`.  
Both `pin` and `val` must be constant values.

### digitalReadFast(pin)

The operation is the same as `digitalRead(pin, val)`.  
`pin` must be a constant value.

