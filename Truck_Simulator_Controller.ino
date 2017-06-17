
#include "Button.h";

const int PIN_BTN_1 = 2;
const int PIN_BTN_2 = 3;

Button b1,b2;

void setup() {
  pinMode(PIN_BTN_1, INPUT);
  pinMode(PIN_BTN_2, INPUT);

  Serial.begin(9600);

  b1.setup(PIN_BTN_1,1);
  b2.setup(PIN_BTN_2,2);
}

void loop() {

  b1.loop();
  b2.loop();
  
}
