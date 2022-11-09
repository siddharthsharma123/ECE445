#include <Arduino.h> 
#include "ultrasonics.h"  
#include "Vector.h"

#define MAX_DISTANCE 400 
#define DELAY_TIME 50

using namespace std; 

Ultrasonics::Ultrasonics(int LeftUltrasonicPin, int MidUltrasonicPin, int RightUltrasonicPin){ 
    this->sonarLeft = new NewPing(LeftUltrasonicPin, LeftUltrasonicPin, MAX_DISTANCE);
    this->sonarMid = new NewPing(MidUltrasonicPin, MidUltrasonicPin, MAX_DISTANCE);
    this->sonarRight = new  NewPing(RightUltrasonicPin, RightUltrasonicPin, MAX_DISTANCE); 
}  

 float Ultrasonics::getLeftDist(void){ 
    delay(DELAY_TIME);
    return sonarLeft->ping_cm(); 
 } 
 
 float Ultrasonics::getRightDist(){
    delay(DELAY_TIME);
    return sonarRight->ping_cm();
  } 

 float Ultrasonics::getMidDist(){
    delay(DELAY_TIME); 
    return sonarMid->ping_cm();
  }
