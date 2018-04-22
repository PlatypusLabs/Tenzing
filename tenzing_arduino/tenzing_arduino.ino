#include <AFMotor.h>
//#include <Servo.h> 

// DC motor on M1,2,3
AF_DCMotor motor_R(1);
AF_DCMotor motor_L(2);
AF_DCMotor motor_S(3);

#define sensorPin 0

#define autoButton 1
#define upButton  2
#define downButton 3
#define forwardButton 4
#define backButton 5

int sensorVal = 0;

int autoVal = 0;
int upVal = 0;
int downVal = 0;
int forwardVal = 0;
int backVal = 0;

bool autoFlag = false;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("****************");
  Serial.println("Tenzing Starting");
  Serial.println("****************");
  
   
  // turn on motor #2
  motor_R.setSpeed(200);
  motor_R.run(RELEASE);

  motor_L.setSpeed(200);
  motor_L.run(RELEASE);

  motor_S.setSpeed(200);
  motor_S.run(RELEASE);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {

  sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value is: ");     
  Serial.println(sensorVal);

  autoVal = analogRead(autoPin);
  Serial.print("Auto value is: ");     
  Serial.println(autoVal);

  upVal = analogRead(upButton);
  Serial.print("Up value is: ");     
  Serial.println(upVal);

  downVal = analogRead(downButton);
  Serial.print("Down value is: ");     
  Serial.println(downVal);

  forwardVal = analogRead(forwardButton);
  Serial.print("Forward value is: ");     
  Serial.println(forwardVal);

  backVal = analogRead(backButton);
  Serial.print("Back value is: ");     
  Serial.println(backVal);

  if (autoFlag){
    
  }
  
  motor_R.run(FORWARD);
  motor_L.run(FORWARD);
  motor_S.run(FORWARD);
  motor_S.setSpeed(255);
//  for (i=0; i<255; i++) {
//    motor_R.setSpeed(i);
//    motor_L.setSpeed(i);
////    motor_S.setSpeed(i);  
//    delay(3);
// }
 
 
 }
}
