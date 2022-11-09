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
    float distanceLeft = sonarLeft->ping_cm();
    if(distanceLeft == 0.0 || distanceLeft >= 100.0){ 
        distanceLeft = MAX_DISTANCE;  
    }
    return distanceLeft;
 } 
 
 float Ultrasonics::getRightDist(){
    delay(DELAY_TIME); 
    float distanceRight = sonarRight->ping_cm();
    if(distanceRight == 0.0 || distanceRight >= 100.0){ 
        distanceRight = MAX_DISTANCE;  
    }
    return distanceRight;
  } 

 float Ultrasonics::getMidDist(){
    delay(DELAY_TIME);  
    float distanceMid = sonarMid->ping_cm();
    if(distanceMid == 0.0 || distanceMid >= 100.0){ 
        distanceMid = MAX_DISTANCE;  
    }
    return distanceMid;
  }  

//  float Ultrasonics::getDist(NewPing * sonar){
//    delay(DELAY_TIME);  
//    float distance = sonar->ping_cm();
//    if(distance == 0.0 || distance >= 100.0){ 
//        distance = MAX_DISTANCE;  
//    }
//    return distance;
// }

 void Ultrasonics::Scan(float (&distance)[NUM_SENSORS]){
//    for(int i = 0; i < NUM_SENSORS; i++){
//        distance[i] = getDist()
//      } 

    distance[0] = this->getLeftDist(); 
    distance[1] = this->getMidDist(); 
    distance[2] = this->getRightDist();
  }
