#include "buttons.h" 
#include <LiquidCrystal_I2C.h>

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
//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{ 
  // Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}
 int i = 0;
void loop()
{ 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pin States:");
  lcd.setCursor(0,1);
  byte buttonsState = buttons->getButtonsPressed(); 
  // Print to serial monitor or LCD
  buttonsState =  ~buttonsState;    
  // if(buttonsState > 0){
  //   i++;
  // }
  // Serial.print("Buttons State: ");
  // Serial.println(buttonsState, DEC); 
  lcd.print(buttonsState); 
  delay(200);
}