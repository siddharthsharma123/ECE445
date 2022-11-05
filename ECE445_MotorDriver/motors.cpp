#include <Arduino.h> 
#include "./motors.h"

using namespace std; 

Motors::Motors(int LeftMotorForward, int LeftMotorBackward, int RightMotorForward, int RightMotorBackward) {
    LeftMotorForward = LeftMotorForward;
    LeftMotorBackward = LeftMotorBackward;
    RightMotorForward = RightMotorForward;
    RightMotorBackward = RightMotorBackward;
}

void Motors::moveForward() {
    
}  

void Motors::turnRight(){
    
}

void Motors::turnLeft(){
    
}

int Motors::getLeftMotorForward() {
    return this.LeftMotorForward;
}