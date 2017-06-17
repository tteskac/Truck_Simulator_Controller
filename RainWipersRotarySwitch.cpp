
#include "RainWipersRotarySwitch.h"

void RainWipersRotarySwitch::setup(
    int rainWipersRotarySwitchPin1, 
    int rainWipersRotarySwitchPin2, 
    int rainWipersRotarySwitchPin3, 
    int joyButton){
  this->_rainWipersRotarySwitchPin1 = rainWipersRotarySwitchPin1;
  this->_rainWipersRotarySwitchPin2 = rainWipersRotarySwitchPin2;
  this->_rainWipersRotarySwitchPin3 = rainWipersRotarySwitchPin3;
  this->_joyButton = joyButton;
}

void RainWipersRotarySwitch::loop(){
    
    //If setup() is not called
    if(_rainWipersRotarySwitchPin1 == NULL) return; 

    /* This will return 1, 2 or 3 if the wiring is ok */
    int reading = 
      (1*digitalRead(_rainWipersRotarySwitchPin1))+
      (2*digitalRead(_rainWipersRotarySwitchPin2))+
      (3*digitalRead(_rainWipersRotarySwitchPin3));

    if (reading != _lastRainWipersRotarySwitchState) {
      _lastDebounceTime = millis();
    }
  
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _rainWipersRotarySwitchState) {
        _rainWipersRotarySwitchState = reading;

        /*
         * RainWipersRotarySwitch logic
         */

        //TURN SLOW
        if(_lastRainWipersRotarySwitchState == 1 && _rainWipersRotarySwitchState == 2){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //TURN FAST
        else if(_lastRainWipersRotarySwitchState == 2 && _rainWipersRotarySwitchState == 3){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //TURN SLOW FROM FAST
        else if(_lastRainWipersRotarySwitchState == 3 && _rainWipersRotarySwitchState == 2){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          delay(50);
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //TURN OFF FROM SLOW
        else if(_lastRainWipersRotarySwitchState == 2 && _rainWipersRotarySwitchState == 1){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          delay(50);
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        /*
         * OTHER COMBINATIONS
         */
        
        //TURN FAST FROM OFF
        else if(_lastRainWipersRotarySwitchState == 1 && _rainWipersRotarySwitchState == 3){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
          delay(50);
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }
        
        //TURN OFF FROM FAST
        else if(_lastRainWipersRotarySwitchState == 3 && _rainWipersRotarySwitchState == 1){
          btnEvent(_joyButton, PRESS);
          delay(50);
          btnEvent(_joyButton, RELEASE);
        }

        //OTHER COMBINATIONS ARE INVALID

      }
    }
  
    _lastRainWipersRotarySwitchState = reading;
}

void RainWipersRotarySwitch::btnEvent(int btn, int state){
  String cmd = ":BTN,";
  cmd += btn; 
  cmd += ",";
  cmd += state;
  cmd += ";";
  Serial.println(cmd);
}

