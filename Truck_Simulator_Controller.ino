
#include "Button.h";
#include "Switch.h";
#include "IgnitionKey.h";

const int PIN_BTN_1 = 2;
const int PIN_BTN_2 = 3;
const int PIN_BTN_3 = 4;
const int PIN_BTN_4 = 5;
const int PIN_BTN_5 = 6;
const int PIN_BTN_6 = 7;

const int PIN_SW_1 = 8;
const int PIN_SW_2 = 9;
const int PIN_SW_3 = 10;

const int PIN_KEY_1 = 10;
const int PIN_KEY_2 = 11;
const int PIN_KEY_3 = 12;

//Object initialization
Button b1,b2,b3,b4,b5,b6;
Switch sw1,sw2,sw3;
IgnitionKey key1;

void setup() {
  pinMode(PIN_BTN_1, INPUT);
  pinMode(PIN_BTN_2, INPUT);
  pinMode(PIN_BTN_3, INPUT);
  pinMode(PIN_BTN_4, INPUT);
  pinMode(PIN_BTN_5, INPUT);
  pinMode(PIN_BTN_6, INPUT);
  pinMode(PIN_SW_1, INPUT);
  pinMode(PIN_SW_2, INPUT);
  pinMode(PIN_SW_3, INPUT);
  pinMode(PIN_KEY_1, INPUT);
  pinMode(PIN_KEY_2, INPUT);
  pinMode(PIN_KEY_3, INPUT);

  Serial.begin(9600);

  b1.setup(PIN_BTN_1, 1);
  b2.setup(PIN_BTN_2, 2);
  b3.setup(PIN_BTN_3, 3);
  b4.setup(PIN_BTN_4, 4);
  b5.setup(PIN_BTN_5, 5);
  b6.setup(PIN_BTN_6, 6);
  sw1.setup(PIN_SW_1, 7);
  sw2.setup(PIN_SW_2, 8);
  sw3.setup(PIN_SW_3, 9);
  key1.setup(PIN_KEY_1, PIN_KEY_2, PIN_KEY_3, 10);
}

void loop() {

/* 6 buttons */
  b1.loop();
  b2.loop();
  b3.loop();
  b4.loop();
  b5.loop();
  b6.loop();

/* Switch 2x
 * On->Off = 1 button click
 * Off->On = 1 button click
 */
  sw1.loop();
  sw2.loop();

/* Push-pull switch - breaks
 * Push = 1 button click
 * Pull = 1 butotn click
 * This is basically the same as a switch so....
 */ 
  sw3.loop();

/* Ignition key
 * 0->1     battery - 1 button click
 * 1->2->1  ignition - 1 button click
 * 1->0     turn off - 1 button click
 */
  key1.loop();

}


/* Light - two buttons
 * 0->1  position lights (L)
 * 1->2  short (L)
 * 2->3  long (K)
 * 3->2  short (K)
 * 2->1  position lights (LL)
 * 1->0  off (Ll)
 */

/* Rain wipers - one button
 * 0->1: 1 button click
 * 1->2: 1 button click
 * 2->1: 2 butoon clicks
 * 1->0: 2 button clicks
 */
