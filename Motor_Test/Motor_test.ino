/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>

Servo ESC1;     // create servo object to control the ESC
Servo ESC2;
Servo ESC3;
Servo ESC4;

long previousMillis = 0;        // will store last time LED was updated
long interval = 6000;           // interval at which to blink (milliseconds)
int stepValue = 1;
int potValue = 0;  // value from the analog pin
bool flag = false;
void setup() {
  Serial.begin(9600);
  // Attach the ESC on pin 9
  ESC1.attach(6,1000,2000); // (pin, min pulse width, max pulse width in microseconds)
  ESC2.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESC3.attach(10,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESC4.attach(11,1000,2000); // (pin, min pulse width, max pulse width in microseconds)  
}

void loop() {
  unsigned long currentMillis = millis();
  Serial.print("Current Throttle: ");
  Serial.print(potValue);
  Serial.println();
  if(currentMillis - previousMillis > interval){
      flag = true;  
  }
  if(potValue >= 25){
    stepValue = 0;
  }
  else if(potValue < 25){
    stepValue = 1;  
  }
  if(flag){
      potValue += stepValue;  
  }
  ESC1.write(potValue);    // Send the signal to the ESC
  ESC2.write(potValue);    // Send the signal to the ESC
  ESC3.write(potValue);    // Send the signal to the ESC
  ESC4.write(potValue);    // Send the signal to the ESC
  delay(1000);
}
