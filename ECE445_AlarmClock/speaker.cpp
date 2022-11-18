#include <Arduino.h> 
#include "speaker.h" 
#include <LiquidCrystal_I2C.h>
#define NUM_CHARS 16 //LCD
#define NUM_ROWS 2 //LCD
#define LCD_I2C_ADDRESS 0x27 

Speaker::Speaker(int speakerPin){
  this->speakerPin = speakerPin;   
} 

void Speaker::Ring(){
  digitalWrite(this->speakerPin, LOW);
} 

void Speaker::Quiet(){
  digitalWrite(this->speakerPin, HIGH);
}