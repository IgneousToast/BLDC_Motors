#include "MotorSM.h"

void setup() {
  Serial.begin(115200);
  initEsc();
  prompt(); 
}

void loop() {
  motorSM();
}
