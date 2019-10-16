#define escPin1         6     //Arduino Nano Pin 6  (PWM)
#define escPin2         9     //Arduino Nano Pin 9  (PWM)
#define escPin3         10    //Arduino Nano Pin 10 (PWM)
#define escPin4         11    //Arduino Nano Pin 11 (PWM)
#define minPulseRate    1000  //Min Pulse Width of PWM
#define maxPulseRate    2000  //Max Pulse Width of PWM
#define minThrottle     0     //Min Value for Throttle (Maps to Min Pulse Width)
#define maxThrottle     180   //Max value for Throttle (Maps to Max Pulse Width)
#define throttleDelay   50    //Delay value in millisec when adjusting motor speed

/*Initial User Prompt*/
void prompt();

/*Initializes ESCs*/
void initEsc();

/*Read User input and verify validity*/
char readUserInput();

/*Rev up them fryers*/
void StartUp();

/*Store current values of motor throttle*/
void storeThrottle(uint8_t selectMotor);

/*Change value of motor throttle*/
void changeThrottle(uint8_t motor,uint8_t throttleValue);

/*Print motor state on console*/
void motorPrint(char key, char *motors[],uint8_t selectMotor);
