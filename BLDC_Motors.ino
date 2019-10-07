#include <Servo.h>

#define escPin1         6     //Arduino Nano Pin 6  (PWM)
#define escPin2         9     //Arduino Nano Pin 9  (PWM)
#define escPin3         10    //Arduino Nano Pin 10 (PWM)
#define escPin4         11    //Arduino Nano Pin 11 (PWM)
#define minPulseRate    1000  //Min Pulse Width of PWM
#define maxPulseRate    2000  //Max Pulse Width of PWM
#define minThrottle     0     //Min Value for Throttle (Maps to Min Pulse Width)
#define maxThrottle     180   //Max value for Throttle (Maps to Max Pulse Width)
#define throttleDelay   50    //Delay value in millisec when adjusting motor speed

unsigned long timer = millis();         //Timer
uint8_t throttle = 0;                   //Sets Motor Throttle value
uint8_t stepValue = 25;                 //Throttle Step Value
uint8_t motorsThrottle[4] = {0,0,0,0};  //Actual Throttle Value
bool startUpFlag  = false;              //Determining Initial ramping up of motors

//uint16_t cnt = 0; 

/*Motor state declarations*/
enum MotorStates {INIT, WAIT, INCREASE, DECREASE, MOTOR_SELECT};
MotorStates motorState = WAIT; 

/*Create ESC objects*/
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;

/*Initial User Prompt*/
void prompt();

/*Initializes ESCs*/
void initEsc();

/*Rev up them fryers*/
void StartUp();

/*Read User input and verify validity*/
char readUserInput();

/*Read current value of motor throttle*/
void readThrottle(uint8_t motor);

/*Change value of motor throttle*/
void changeThrottle(uint8_t motor,uint8_t throttleValue);

/* Code to flush serial buffer*/
void Sflush();

/*Motor State Machine*/
void motorSM(uint8_t throttle){
  switch(motorState){
    //Buffer State in case keyboard button is held. 
    case INIT: 
      motorState = WAIT;
      break;
    }
    
    //Wait for user input
    //If user input is read, switch to appropriate state
    case WAIT:{
      char key = ' ';
      key = readUserInput();
      if(key == 'W'){
        motorState = INCREASE;  
      }
      else if(key == 'S'){
        motorState = DECREASE;  
      }
      else if((key == 'A')||(key == 'D')){
        motorState = MOTOR_SELECT;  
      }
      else if(key == 'E'){
        motorState = WAIT;  
      }
      break;
    }
    case INCREASE: {
      
      
      /*Serial.print("I am in increase state! ");
      Serial.println();
      Serial.print("Going to Wait now :)");
      Serial.println();
      cnt += 1;
      */
      motorState = WAIT;
      break;
    }
    case DECREASE: {
      Serial.print("I am in decrease state! ");
      Serial.println();
      Serial.print("Going to Wait now :)");
      Serial.println();
       cnt += 1;
      motorState = WAIT;
      break;
    }
    case MOTOR_SELECT: {
      Serial.print("You want to select a motor? pshhh! ");
      Serial.println();
      Serial.print("Going to Wait now :)");
      Serial.println();
       cnt += 1;
      motorState = WAIT;
      break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  initEsc();
  prompt(); 
}

void loop() {
  motorSM(throttle);
}


void prompt(){
  Serial.print("Motor Controller:");
  Serial.println();
  Serial.print("Press \'W\' to increase speed.");
  Serial.println();
  Serial.print("Press \'S\' to decrease speed.");
  Serial.println();
  Serial.print("Press \'A\' or \'D\' to select motor.");
  Serial.println();
}

void initEsc(){
  ESC1.attach(escPin1, minPulseRate, maxPulseRate);
  ESC2.attach(escPin2, minPulseRate, maxPulseRate);
  ESC3.attach(escPin3, minPulseRate, maxPulseRate);
  ESC4.attach(escPin4, minPulseRate, maxPulseRate);
  return; 
}

char readUserInput(){

  char key = ' ';
  int incomingData;

  if(Serial.available() > 0 ) {
    incomingData = Serial.read();
  } 
  else { //idk if you need this statement?
    return 'E';  
  }
  
  //If for whatever reason it fails to read, return E
  if(incomingData == -1) {
    Serial.print("failed");
    return 'E';
  }
  
  Serial.print(cnt);
  Serial.print(": ");
  Serial.print(incomingData);
  Serial.println();

  switch(incomingData){
    case 119 : {
      key = 'W';
      break;
    }

    case 97 : {
      key = 'A';
      break;
    }
  
    case 115 : {
      key = 'S';
      break;  
    }
 
    case 100 :  {
      key = 'D';
      break;
    }

    default : {
      key = 'E';
      Serial.print("Error: Please enter valid key");
      Serial.print(incomingData);
      Serial.println();  
      break;
    }
  }
  return key;
}

void readThrottle(){ 
}

void Sflush(){
  while(Serial.available()) {
    Serial.read();
  }  
}
