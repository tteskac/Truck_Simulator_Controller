
#ifndef RainWipersRotarySwitch_h
#define RainWipersRotarySwitch_h

#include "Arduino.h"

class RainWipersRotarySwitch 
{

  //CONSTANTS
  const bool PRESS = 1;
  const bool RELEASE = 0;
  
  public:
    void setup(
      int rainWipersRotarySwitchPin1, 
      int rainWipersRotarySwitchPin2, 
      int rainWipersRotarySwitchPin3, 
      int joyButton);
      
    void loop();
    
  private:
    int _rainWipersRotarySwitchPin1, _rainWipersRotarySwitchPin2, _rainWipersRotarySwitchPin3; //rainWipersRotarySwitch pins
    int _joyButton;                              // the number of the joystick buttons for off/slow/fast 
    int _rainWipersRotarySwitchState;               // the current reading from the input pins
    int _lastRainWipersRotarySwitchState = 0;      // the previous reading from the input pin
    long _lastDebounceTime = 0;               // the last time the output pin was toggled
    long _debounceDelay = 50;

    void btnEvent(int btn, int state);
};

#endif




