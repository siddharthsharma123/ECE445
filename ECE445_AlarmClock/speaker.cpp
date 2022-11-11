#include <"Arduino.h"> 
#include "speaker.h" 

Speaker::Speaker(int speakerPin){
  this->speakerPin = speakerPin;
} 

void Speaker::ring(){
    // put your main code here, to run repeatedly:
  digitalWrite(this->speakerPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(this->speakerPin, LOW);
  delayMicroseconds(1000);
}