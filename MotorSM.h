#include "BLDC_Motors.h"
/*Motor state declarations*/
enum MotorStates {INIT, WAIT, INCREASE, DECREASE, MOTOR_SELECT};
MotorStates motorState = WAIT; 

/*Motor State Machine*/
void motorSM(){
  switch(motorState){
    //Buffer State in case keyboard button is held. 
    case INIT:{ 
      motorState = WAIT;
      break;
    }
    
    //Wait for user input
    //If user input is read, switch to appropriate state
    case WAIT:{
      key = ' ';
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
      motorPrint(key, motors, selectMotor);
      motorState = WAIT;
      break;
    }
    case DECREASE: {
      motorPrint(key, motors, selectMotor);
      motorState = WAIT;
      break;
    }
    case MOTOR_SELECT: {
      if(key == 'A'){
        selectMotor = 4;
      }
      else if(key == 'D'){
        if(selectMotor >= 3){
          selectMotor = 0;
        }
        else{
          selectMotor += 1;
        }
      }
      motorPrint(key, motors, selectMotor);
      motorState = WAIT;
      break;
    }
  }
}
