
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button 
{
  
  public:
    void setup(int buttonPin, int joyButton);
    void loop();
    
  private:
    int _buttonPin;                 // the number of the pushbutton pin
    int _joyButton;                 // the number of the joystich button
    int _buttonState;               // the current reading from the input pin
    int _lastButtonState = LOW;     // the previous reading from the input pin
    long _lastDebounceTime = 0;     // the last time the output pin was toggled
    long _debounceDelay = 50;
  
};

#endif




