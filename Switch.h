
#ifndef Switch_h
#define Switch_h

#include "Arduino.h"

class Switch 
{

  //CONSTANTS
  const bool PRESS = 1;
  const bool RELEASE = 0;
  
  public:
    void setup(int switchPin, int joyButton);
    void loop();
    
  private:
    int _switchPin;                 // the number of the switch pin
    int _joyButton;                 // the number of the joystick button
    int _switchState;               // the current reading from the input pin
    int _lastSwitchState = LOW;     // the previous reading from the input pin
    long _lastDebounceTime = 0;     // the last time the output pin was toggled
    long _debounceDelay = 50;
    
};

#endif




