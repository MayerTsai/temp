#include "my_button.h"

const unsigned long DEBOUNCE_TIME = 50;

Button::Button(byte pin) : _pin(pin), _state(HIGH), _last_reading(HIGH), _last_debounce_time(0)
{
  // Using INPUT_PULLUP is a good practice for buttons.
  // This means the button is HIGH when not pressed, and LOW when pressed.
  // The original code used INPUT, which requires an external pull-up or pull-down resistor.
  // Given the logic in LedDriver checks for LOW as pressed, a pull-up is implied.
  pinMode(_pin, INPUT_PULLUP);
}

byte Button::update()
{
  byte new_reading = digitalRead(_pin);

  if (new_reading != _last_reading)
  {
    _last_debounce_time = millis();
  }

  if ((millis() - _last_debounce_time) > DEBOUNCE_TIME)
  {
    _state = new_reading;
  }

  _last_reading = new_reading;
  return _state;
}