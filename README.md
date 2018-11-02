# UnoFastLib
Library to do replace with constant expression at compile time for Arduino UNO (ATmega328P) C++14 compiler

**!!Warning!!**  
I only checked the operation with Arduino IDE 1.8.7 on Windows 10.

## Methods

### digitalWriteFast(pin, val)

The operation is the same as `digitalWrite(pin, val)`.  
Both `pin` and `val` must be constant values.

### digitalReadFast(pin)

The operation is the same as `digitalRead(pin)`.  
`pin` must be a constant value.

## Example

```c
#include <UnoFastLib.hpp>
constexpr uint8_t SW = 8;
constexpr uint8_t LED = 13;
uint32_t cnt = 0, i;
bool p = false;
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}
void loop() {
  cnt = 0;
  while (digitalReadFast(SW) == HIGH);
  while (digitalReadFast(SW) == LOW)  ++cnt;
  Serial.println(cnt);
  for (i = 0; i < cnt; ++i) {
    p = !p;
    if (p) digitalWriteFast(LED, HIGH);
    else  digitalWriteFast(LED, LOW);

    // WARNING!!  This code is compile error.
    // digitalWriteFast(LED, p);
  }
  digitalWriteFast(LED, LOW);
}
```
