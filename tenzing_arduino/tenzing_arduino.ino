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

int driveSpeed = 120;

int sensorVal = 0;
int sensorThreshold = 500;
int sensorTol = 50;


int autoVal = 0;
int upVal = 0;
int downVal = 0;
int forwardVal = 0;
int backVal = 0;

bool autoFlag = true;

bool debug = false;

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

//  Read Values
  sensorVal = analogRead(sensorPin);
  autoVal = analogRead(autoButton);
  upVal = analogRead(upButton);
  downVal = analogRead(downButton);
  forwardVal = analogRead(forwardButton);
  backVal = analogRead(backButton);

  
//Optional Print Values
  if (debug){
 
    Serial.print("Auto value is: ");     
    Serial.println(autoVal);
  
    Serial.print("Up value is: ");     
    Serial.println(upVal);
  
    Serial.print("Down value is: ");     
    Serial.println(downVal);
  
    Serial.print("Forward value is: ");     
    Serial.println(forwardVal);
  
    Serial.print("Back value is: ");     
    Serial.println(backVal);
  }
  
// Set or unset autoFlag
// 800 is a misc. button threshold
  if (autoVal > 800){
    if (autoFlag){
      autoFlag = false;
    }
    else{
      autoFlag = true;
    }
  }

//Autonomous control
  if (autoFlag){
    Serial.print("Sensor value is: ");     
    Serial.println(sensorVal);

    if (sensorVal < sensorThreshold - sensorTol){
      motor_R.run(BACKWARD);
      motor_L.run(BACKWARD);
      motor_R.setSpeed(driveSpeed);
      motor_L.setSpeed(driveSpeed);
      motor_S.setSpeed(0);
    }
    else if (sensorVal > sensorThreshold + sensorTol) {
      motor_R.run(FORWARD);
      motor_L.run(FORWARD);
      motor_R.setSpeed(driveSpeed);
      motor_L.setSpeed(driveSpeed);
      motor_S.setSpeed(0);
    }
    else{
      motor_R.setSpeed(0);
      motor_L.setSpeed(0);
      motor_S.run(FORWARD);
      motor_S.setSpeed(255);
    }
    
  }

//Manual Control
  else{
    if (upVal > 800){
      motor_S.run(FORWARD);
      motor_S.setSpeed(255);
    }
    else if (downVal > 800){
      motor_S.run(BACKWARD);
      motor_S.setSpeed(255);  
    }
    else if (forwardVal > 800){
      motor_R.run(FORWARD);
      motor_L.run(FORWARD);
      motor_R.setSpeed(driveSpeed);
      motor_L.setSpeed(driveSpeed);
    }
    else if (backVal > 800){
      motor_R.run(BACKWARD);
      motor_L.run(BACKWARD);
      motor_R.setSpeed(driveSpeed);
      motor_L.setSpeed(driveSpeed);
    }
    else{
      motor_R.setSpeed(0);
      motor_L.setSpeed(0);
      motor_S.setSpeed(0);
    }
  }
 
 }

