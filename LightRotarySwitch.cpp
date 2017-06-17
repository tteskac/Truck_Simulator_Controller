
#include "LightRotarySwitch.h"

void LightRotarySwitch::setup(
    int lightRotarySwitchPin1, 
    int lightRotarySwitchPin2, 
    int lightRotarySwitchPin3, 
    int lightRotarySwitchPin4, 
    int joyButton1, 
    int joyButton2){
  this->_lightRotarySwitchPin1 = lightRotarySwitchPin1;
  this->_lightRotarySwitchPin2 = lightRotarySwitchPin2;
  this->_lightRotarySwitchPin3 = lightRotarySwitchPin3;
  this->_lightRotarySwitchPin4 = lightRotarySwitchPin4;
  this->_joyButton1 = joyButton1;
  this->_joyButton2 = joyButton2;
}

void LightRotarySwitch::loop(){
    
    //If setup() is not called
    if(_lightRotarySwitchPin1 == NULL) return; 

    /* This will return 1, 2, 3 or 4 if the wiring is ok */
    int reading = 
      (1*digitalRead(_lightRotarySwitchPin1))+
      (2*digitalRead(_lightRotarySwitchPin2))+
      (3*digitalRead(_lightRotarySwitchPin3))+
      (4*digitalRead(_lightRotarySwitchPin4));

    if (reading != _lastLightRotarySwitchState) {
      _lastDebounceTime = millis();
    }
  
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
      if (reading != _lightRotarySwitchState) {
        _lightRotarySwitchState = reading;

        /*
         * LightRotarySwitch logic
         */

        //POSITION LIGHT
        if(_lastLightRotarySwitchState == 1 && _lightRotarySwitchState == 2){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }

        //SHORT LIGHTS
        else if(_lastLightRotarySwitchState == 2 && _lightRotarySwitchState == 3){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }

        //LONG LIGHTS
        else if(_lastLightRotarySwitchState == 3 && _lightRotarySwitchState == 4){
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
        }

        //TURN OFF LONG LIGHTS
        else if(_lastLightRotarySwitchState == 4 && _lightRotarySwitchState == 3){
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
        }
        
        //TURN OFF SHORT LIGHTS - POSITION LIGHTS ON
        else if(_lastLightRotarySwitchState == 3 && _lightRotarySwitchState == 2){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }

        //TURN OFF COMPLETELY
        else if(_lastLightRotarySwitchState == 2 && _lightRotarySwitchState == 1){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }

        /*
         * OTHER COMBINATIONS
         */
        
        //FROM OFF TO SHORT
        else if(_lastLightRotarySwitchState == 1 && _lightRotarySwitchState == 3){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }
        
        //FROM OFF TO LONG
        else if(_lastLightRotarySwitchState == 1 && _lightRotarySwitchState == 4){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
        }

        //FROM OFF TO LONG
        else if(_lastLightRotarySwitchState == 1 && _lightRotarySwitchState == 4){
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
        }
        
        //FROM LONG TO POSITION
        else if(_lastLightRotarySwitchState == 4 && _lightRotarySwitchState == 2){
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }

        //FROM LONG TO OFF
        else if(_lastLightRotarySwitchState == 4 && _lightRotarySwitchState == 1){
          btnEvent(_joyButton2, PRESS);
          delay(50);
          btnEvent(_joyButton2, RELEASE);
          delay(50);
          btnEvent(_joyButton1, PRESS);
          delay(50);
          btnEvent(_joyButton1, RELEASE);
        }
        
        //OTHER COMBINATIONS ARE INVALID

      }
    }
  
    _lastLightRotarySwitchState = reading;
}

void LightRotarySwitch::btnEvent(int btn, int state){
  String cmd = ":BTN,";
  cmd += btn; 
  cmd += ",";
  cmd += state;
  cmd += ";";
  Serial.println(cmd);
}

