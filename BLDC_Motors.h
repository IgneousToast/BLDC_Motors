#include <Servo.h>
#include "definitions.h"
/*Create ESC objects*/
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;

unsigned long timer = millis();                 //Timer
uint8_t       throttle = 0;                     //Sets Motor Throttle value
uint8_t       stepValue = 25;                   //Throttle Step Value
uint8_t       motorsThrottle[4] = {0,0,0,0};    //Actual Throttle Value
bool          startUpFlag  = false;             //Determining Initial ramping up of motors
char          key = ' ';                        //User Keyboard Input
char*         motors[] = {"Motor 1", "Motor 2",
                          "Motor 3", "Motor 4", //Motor string array 
                          "All Motors"};
uint8_t       selectMotor = 4;                   //Motor selection flag, 0 = Motor 1;   
                                                //Motor selection flag, 1 = Motor 2;   
                                                //Motor selection flag, 2 = Motor 3;   
                                                //Motor selection flag, 3 = Motor 4;   
                                                //Motor selection flag, 4 = ALL MOTORS;
/*Initial User Prompt*/
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
  int incomingData;

  if(Serial.available() > 0 ) {
    incomingData = Serial.read();
  } 
  else { //idk if you need this statement? Just in case lol
    return 'E';  
  }
  
  //If for whatever reason it fails to read, return E
  if(incomingData == -1) {
    Serial.print("failed");
    return 'E';
  }

  switch(incomingData){
    case 119 : {
      return 'W';
    }

    case 97 : {
      return 'A';
    }
  
    case 115 : {
      return 'S';
    }
 
    case 100 :  {
      return 'D';
    }

    default : {
      Serial.print("Error: Please enter valid key");
      Serial.print(incomingData);
      Serial.println();  
      return 'E';
    }
  }
}

void StartUp(){
  changeThrottle(4, 25); 
  return;
}

void storeThrottle(uint8_t selectMotor){ 
  uint8_t esc_throttle = 0;
  switch(selectMotor){
    case 0: {
      esc_throttle = ESC1.read();
      motorsThrottle[selectMotor, esc_throttle];
      break;  
    }
    case 1:{
      esc_throttle = ESC2.read();
      motorsThrottle[selectMotor, esc_throttle];
      break;
    }

    case 2:{
      esc_throttle = ESC3.read();
      motorsThrottle[selectMotor, esc_throttle];
      break;
    }
    case 3:{
      esc_throttle = ESC4.read();
      motorsThrottle[selectMotor, esc_throttle];
      break;
    }
    case 4:{
      esc_throttle = ESC1.read();
      motorsThrottle[selectMotor, esc_throttle];
      esc_throttle = ESC2.read();
      motorsThrottle[selectMotor, esc_throttle];
      esc_throttle = ESC3.read();
      motorsThrottle[selectMotor, esc_throttle];
      esc_throttle = ESC4.read();
      motorsThrottle[selectMotor, esc_throttle];
      break;
      
    }
  }
}


void changeThrottle(uint8_t motor,uint8_t throttleValue){
  int currentThrottle = motorsThrottle[motor];
  if(currentThrottle == 0){
      
  }
}

void motorPrint(char key, char *motors[], uint8_t motor){
    switch(key){
      case 'W': {
        Serial.print("Increasing ");
        Serial.print(motors[motor]);
        Serial.print("!");
        Serial.println();
        break;  
      }
      case 'S': {
        Serial.print("Decreasing ");
        Serial.print(motors[motor]);
        Serial.print("!");
        Serial.println();
        break;  
      }  
      case 'A': {
        Serial.print("Selecting ");
        Serial.print(motors[motor]);
        Serial.print("!");
        Serial.println();
        break;  
      }  
      case 'D': {
        Serial.print("Selecting ");
        Serial.print(motors[motor]);
        Serial.print("!");
        Serial.println();
        break;  
      }
      default: {
        Serial.print("Error! (Motor Print) ");
        Serial.print(motors[motor]);
        Serial.print("!");
        Serial.println();
        break;   
      }      
    }
    return;
}
