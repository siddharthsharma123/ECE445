#include "ultrasonics.h"
#include "Vector.h" 

#define LeftUltrasonicPin 10 
#define MidUltrasonicPin 11 
#define RightUltrasonicPin 12  

Ultrasonics ultrasonics(LeftUltrasonicPin, MidUltrasonicPin, RightUltrasonicPin);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 

}


void loop() {
//  float * distances = ultrasonics.Scan(); 
     Serial.print(ultrasonics.getLeftDist());   
     Serial.print(" cm ");
     Serial.print(ultrasonics.getMidDist());   
     Serial.print(" cm ");
     Serial.print(ultrasonics.getRightDist());   
     Serial.print(" cm "); 
     Serial.println(" "); 
//     return distances;
}
