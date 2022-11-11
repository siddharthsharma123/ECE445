#include <"Arduino.h">
#include "buttons.h"   

Buttons::Buttons(int loadPin, int clockEnablePin, int clockInPin,  int dataInPin){
    this->loadPin = loadPin; 
    this->clockEnablePin = clockEnablePin; 
    this->dataInPin = dataInPin; 
    this->clockInPin = clockInPin; 

    pinMode(loadPin, OUTPUT);
    pinMode(clockEnablePin, OUTPUT);
    pinMode(clockInPin, OUTPUT);
    pinMode(dataInPin, INPUT);
} 

byte Buttons::getButtonsPressed(){
  digitalWrite(this->loadPin, LOW);
  delayMicroseconds(5);
  digitalWrite(this->loadPin, HIGH);
  delayMicroseconds(5);
 
  // Get data from 74HC165
  digitalWrite(this->clockIn, HIGH);
  digitalWrite(this->clockEnablePin, LOW);
  byte incoming = shiftIn(this->dataInPin, this->clockIn, LSBFIRST);
  digitalWrite(this->clockEnablePin, HIGH);
  delay(200);
}
