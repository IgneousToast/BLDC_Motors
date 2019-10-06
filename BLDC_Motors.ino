#include <Servo.h>

#define escPin1         6     //Arduino Nano Pin 6  (PWM)
#define escPin2         9     //Arduino Nano Pin 9  (PWM)
#define escPin3         10    //Arduino Nano Pin 10 (PWM)
#define escPin4         11    //Arduino Nano Pin 11 (PWM)
#define minPulseRate    1000  //Min Pulse Width of PWM
#define maxPulseRate    2000  //Max Pulse Width of PWM
#define minThrottle     0     //Min Value for Throttle (Maps to Min Pulse Width)
#define maxThrottle     180   //Max value for Throttle (Maps to Max Pulse Width)

unsigned long chrono = millis();  //timer
uint8_t throttle;                 //motor throttle value

/*Motor state declarations*/
enum MotorStates {INIT, WAIT, INCREASE, DECREASE, MOTOR_SELECT};
MotorStates motorState = INIT; 

/*Create ESC objects*/
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;

/*Initializes ESCs*/
void initEsc();

/*Rev up them fryers*/
void StartUp();

/*Read current value of motor throttle*/
void readThrottle(uint8_t motor);

/*Change value of motor throttle*/
void changeThrottle(uint8_t motor,uint8_t throttleValue);

/*Motor State Machine*/
void motorSM(uint8_t throttle){
  switch(motorState){
    case INIT: {
      break;
    }
    case WAIT:{
      break;
    }
    case INCREASE: {
      break;
    }
    case DECREASE: {
      break;
    }
    case MOTOR_SELECT: {
      break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  initEsc();
}

void loop() {
  motorSM(throttle);
}

void initEsc(){
  ESC1.attach(escPin1, minPulseRate, maxPulseRate);
  ESC2.attach(escPin2, minPulseRate, maxPulseRate);
  ESC3.attach(escPin3, minPulseRate, maxPulseRate);
  ESC4.attach(escPin4, minPulseRate, maxPulseRate);
  return; 
};
