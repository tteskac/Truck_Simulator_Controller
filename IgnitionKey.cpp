
#include "IgnitionKey.h"

void IgnitionKey::setup(
    int ignitionKeyPin1, 
    int ignitionKeyPin2, 
    int ignitionKeyPin3, 
    int joyButton){
  this->_ignitionKeyPin1 = ignitionKeyPin1;
  this->_ignitionKeyPin2 = ignitionKeyPin2;
  this->_ignitionKeyPin3 = ignitionKeyPin3;
  this->_joyButton = joyButton;
}

void IgnitionKey::loop(){
    
    //If setup() is not called
    if(_ignitionKeyPin1 == NULL) return; 

    /* This will return 1, 2 or 3 if the wiring is ok */
    int reading = 
      (1*digitalRead(_ignitionKeyPin1))+
      (2*digitalRead(_ignitionKeyPin2))+
      (3*digitalRead(_ignitionKeyPin3));

    if (reading != _lastIgnitionKeyState) {
      _lastDebounceTime = millis();
    }
  
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _ignitionKeyState) {
        _ignitionKeyState = reading;

        /*
         * IgnitionKey logic
         */

        //BATTERY CONTACT
        if(_lastIgnitionKeyState == 1 && _ignitionKeyState == 2 && _ignitionOn == false){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //IGNITION
        else if(_lastIgnitionKeyState == 2 && _ignitionKeyState == 3 && _ignitionOn == false){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          _ignitionOn == true;
        }

        //TURN OFF
        else if(_lastIgnitionKeyState == 2 && _ignitionKeyState == 1 && _ignitionOn == true){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          _ignitionOn == false;
        }

        //TURN OFF CONTACT
        else if(_lastIgnitionKeyState == 2 && _ignitionKeyState == 1 && _ignitionOn == false){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          delay(50);
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //OTHER COMBINATIONS ARE INVALID

      }
    }
  
    _lastIgnitionKeyState = reading;
}

void IgnitionKey::btnEvent(int btn, int state){
  String cmd = ":BTN,";
  cmd += btn; 
  cmd += ",";
  cmd += state;
  cmd += ";";
  Serial.println(cmd);
}

