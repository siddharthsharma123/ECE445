#include "buttons.h"
// Define Connections to 74HC165
 
// PL pin 1
int load = 7;
// CE pin 15
int clockEnablePin = 4; 
// CP pin 2
int clockIn = 6;
// Q7 pin 7
int dataIn = 5;

Buttons * buttons = new Buttons(load, clockEnablePin, clockIn, dataIn);

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
  
}
 
void loop()
{
  byte buttonsState = buttons->getButtonsPressed(); 
  // Print to serial monitor
  Serial.print("Pin States:\r\n");
  Serial.println(buttonsState, BIN);
}