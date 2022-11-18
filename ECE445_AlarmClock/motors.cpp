#include <Arduino.h> 
#include "motors.h"

using namespace std; 

Motors::Motors(int LeftMotorForward, int LeftMotorBackward, int RightMotorForward, int RightMotorBackward) {
    this->LeftMotorForward = LeftMotorForward;
    this->LeftMotorBackward = LeftMotorBackward;
    this->RightMotorForward = RightMotorForward;
    this->RightMotorBackward = RightMotorBackward;
}

void Motors::moveForward() {
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void Motors::moveBackward() {
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
  
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW);
}

void Motors::turnRight(){
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorBackward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorForward, LOW);
  
    delay(500);
  
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}

void Motors::turnLeft(){
    digitalWrite(LeftMotorBackward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);

    delay(500);
  
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
} 

void Motors::stopMotors(){
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
    digitalWrite(LeftMotorForward, LOW); 
    digitalWrite(RightMotorForward, LOW);
  }

int Motors::getLeftMotorForward() {
    return this->LeftMotorForward;
}
