
#include "Button.h"

void Button::setup(int buttonPin, int buttonNumber){
  this->_buttonPin = buttonPin;
  this->_buttonNumber = buttonNumber;
}

void Button::loop(){

    if(_buttonPin == NULL) return;  //If setup() is not called
  
    int reading = digitalRead(_buttonPin);

    if (reading != _lastButtonState) {
      _lastDebounceTime = millis();
    }
  
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _buttonState) {
        _buttonState = reading;

        String cmd = ":BTN,";
        cmd += _buttonNumber; 
        cmd += ",";
        cmd += _buttonState;
        cmd += ";";
        Serial.println(cmd);
      }
    }
  
    _lastButtonState = reading;
}
