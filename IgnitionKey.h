
#ifndef IgnitionKey_h
#define IgnitionKey_h

#include "Arduino.h"

class IgnitionKey 
{

  //CONSTANTS
  const bool PRESS = 1;
  const bool RELEASE = 0;
  
  public:
    void setup(
      int ignitionKeyPin1, 
      int ignitionKeyPin2, 
      int ignitionKeyPin3, 
      int joyButton);
      
    void loop();
    
  private:
    int _ignitionKeyPin1, _ignitionKeyPin2, _ignitionKeyPin3; //ignitionKey pins
    int _joyButton;                      // the number of the joystick button for on/off
    int _ignitionKeyState;               // the current reading from the input pins
    int _lastIgnitionKeyState = 0;      // the previous reading from the input pin
    long _lastDebounceTime = 0;         // the last time the output pin was toggled
    long _debounceDelay = 50;
    bool _ignitionOn = false;

    void btnEvent(int btn, int state);
};

#endif




