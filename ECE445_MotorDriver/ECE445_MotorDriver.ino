#include "data/motor_driver.cpp"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
Motors motors(4,5,6,7); 

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(motors.getLeftMotorForward());
  //Serial.print(0);
}
