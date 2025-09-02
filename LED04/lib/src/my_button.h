#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button
{
private:
  const byte _pin;
  byte _state;
  byte _last_reading;
  unsigned long _last_debounce_time;

public:
  Button(byte pin);
  ~Button() = default;
  Button(const Button &) = delete;            // Prevent create copying
  Button &operator=(const Button &) = delete; // Prevent assignment copying

  byte update();
};

#endif // MY_BUTTON_H