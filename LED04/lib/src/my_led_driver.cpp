#include "my_led_driver.h"

const unsigned long SHORT_TIME_MS = 500;
const unsigned long LONG_TIME_MS = 1000;
const unsigned long BLINKING_TIME_MS = 500;

LedDriver::LedDriver(Led &led, Button &sw) : _led(led), _sw(sw),
                                             _button_state(button_state_t::PRESSED),
                                             _last_button_state_time(millis()),
                                             _command(light_command_t::LIGHT_OFF),
                                             _led_state(LOW),
                                             _last_blinking_time(0)
{
}

void LedDriver::update_led()
{
  unsigned long pressed_duration = get_duration_ms();

  /*
  byte reading = _sw.update();
  button_state_t current_state = (reading == LOW) ? button_state_t::PRESSED : button_state_t::RELEASED;

  if (current_state != _button_state)
  {
    unsigned long now = millis();
    if (current_state == button_state_t::PRESSED)
      _last_button_state_time = now;
    else
      pressed_duration = now - _last_button_state_time;
    _button_state = current_state;
  }
  */

  if (pressed_duration > 0)
  {
    if (pressed_duration < SHORT_TIME_MS)
      _command = light_command_t::LIGHT_ON;
    else if (pressed_duration < LONG_TIME_MS)
      _command = light_command_t::LIGHT_TOGGLE;
    else // Long press turns it off
      _command = light_command_t::LIGHT_OFF;
  }

  switch (_command)
  {
  case light_command_t::LIGHT_OFF:
    _led_state = LOW;
    break;
  case light_command_t::LIGHT_ON:
    _led_state = HIGH;
    break;
  case light_command_t::LIGHT_TOGGLE:
  {
    unsigned long now = millis();
    if (now - _last_blinking_time >= BLINKING_TIME_MS)
    {
      _led_state = !_led_state;
      _last_blinking_time = now;
    }
  }
  break;
  }
  _led.set_led(_led_state);
}

unsigned long LedDriver::get_duration_ms()
{
  unsigned long pressed_duration = 0;
  byte reading = _sw.update();
  button_state_t current_state = (reading == LOW) ? button_state_t::PRESSED : button_state_t::RELEASED;

  if (current_state != _button_state)
  {
    unsigned long now = millis();
    if (current_state == button_state_t::PRESSED)
      _last_button_state_time = now;
    else
    {
      pressed_duration = now - _last_button_state_time;
      _last_button_state_time = 0;
    }
    _button_state = current_state;
  }
  return pressed_duration;
}

/*
void LedDriver::set_command(unsigned long duration)
{
  if (duration > 0)
  {
    if (duration < SHORT_TIME_MS)
      _command = light_command_t::LIGHT_ON;
    else if (duration < LONG_TIME_MS)
      _command = light_command_t::LIGHT_TOGGLE;
    else // Long press turns it off
      _command = light_command_t::LIGHT_OFF;
  }
}
*/
/*
void LedDriver::set_led_state()
{
  switch (_command)
  {
  case light_command_t::LIGHT_OFF:
    _led_state = LOW;
    break;
  case light_command_t::LIGHT_ON:
    _led_state = HIGH;
    break;
  case light_command_t::LIGHT_TOGGLE:
  {
    unsigned long now = millis();
    if (now - _last_blinking_time >= BLINKING_TIME_MS)
    {
      _led_state = !_led_state;
      _last_blinking_time = now;
    }
  }
  break;
  }
}
*/