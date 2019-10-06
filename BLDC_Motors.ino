#include <Servo.h>

//Motor state declarations
enum MotorStates {INIT, WAIT, INCREASE, DECREASE, MOTOR_SELECT};
MotorStates motorstate = INIT; 

//Create ESC objects
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;

//ESC pins, PWM pins on Arduino Nano
uint8_t escPin1 = 6;
uint8_t escPin1 = 9;
uint8_t escPin1 = 10;
uint8_t escPin1 = 11;

//Min/Max pulse frequency of PWM 

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
