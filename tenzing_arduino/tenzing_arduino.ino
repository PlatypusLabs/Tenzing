#include <AFMotor.h>
//#include <Servo.h> 

// DC motor on M1,2,3
AF_DCMotor motor_R(1);
AF_DCMotor motor_L(2);
AF_DCMotor motor_S(3);


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
  motor_R.run(FORWARD);
  motor_L.run(FORWARD);
  motor_S.run(FORWARD);
  motor_S.setSpeed(255);
  for (i=0; i<255; i++) {
    motor_R.setSpeed(i);
    motor_L.setSpeed(i);
//    motor_S.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor_R.setSpeed(i);
    motor_L.setSpeed(i);
//    motor_S.setSpeed(i);  
    delay(3);
 }
 
  motor_R.run(BACKWARD);
  motor_L.run(BACKWARD);
//  motor_S.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor_R.setSpeed(i);
    motor_L.setSpeed(i);
//    motor_S.setSpeed(i);  
    delay(3);
 }
 
  for (i=255; i!=0; i--) {
    motor_R.setSpeed(i); 
    motor_L.setSpeed(i);
//    motor_S.setSpeed(i); 
    delay(3);
 }
}
