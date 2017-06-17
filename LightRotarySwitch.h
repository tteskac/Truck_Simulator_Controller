
#ifndef LightRotarySwitch_h
#define LightRotarySwitch_h

#include "Arduino.h"

class LightRotarySwitch 
{

  //CONSTANTS
  const bool PRESS = 1;
  const bool RELEASE = 0;
  
  public:
    void setup(
      int lightRotarySwitchPin1, 
      int lightRotarySwitchPin2, 
      int lightRotarySwitchPin3, 
      int lightRotarySwitchPin4, 
      int joyButton1,
      int joyButton2);
      
    void loop();
    
  private:
    int _lightRotarySwitchPin1, _lightRotarySwitchPin2, _lightRotarySwitchPin3, _lightRotarySwitchPin4; //lightRotarySwitch pins
    int _joyButton1, _joyButton2;               // the number of the joystick buttons for on/off and short/long lights
    int _lightRotarySwitchState;               // the current reading from the input pins
    int _lastLightRotarySwitchState = 0;      // the previous reading from the input pin
    long _lastDebounceTime = 0;               // the last time the output pin was toggled
    long _debounceDelay = 50;

    void btnEvent(int btn, int state);
};

#endif




