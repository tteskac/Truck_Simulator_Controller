
#include "Switch.h"

void Switch::setup(int switchPin, int switchNumber){
  this->_switchPin = switchPin;
  this->_switchNumber = switchNumber;
}

void Switch::loop(){

    if(_switchPin == NULL) return;  //If setup() is not called
  
    int reading = digitalRead(_switchPin);

    if (reading != _lastSwitchState) {
      _lastDebounceTime = millis();
    }
  
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _switchState) {
        _switchState = reading;

        /*
         */

        //PRESS
        String cmd = ":BTN,";
        cmd += _switchNumber; 
        cmd += ",";
        cmd += PRESS;
        cmd += ";";
        Serial.println(cmd);

        //DELAY
        delay(50);

        //RELEASE
        cmd = ":BTN,";
        cmd += _switchNumber; 
        cmd += ",";
        cmd += RELEASE;
        cmd += ";";
        Serial.println(cmd);

        
      }
    }
  
    _lastSwitchState = reading;
}