#include <LiquidCrystal_I2C.h>
#include <DS3231.h>  
#include "buttons.h"

#define NUM_CHARS 16 //LCD
#define NUM_ROWS 2 //LCD
#define LCD_I2C_ADDRESS 0x27  
#define CLOCK_ENABLE_PIN 4 
#define DATA_IN_PIN 5 
#define CLOCK_IN_PIN 6
#define LOAD_IN 7 

using namespace std;

// Initialize the DS3231 real time clock (RTC)
DS3231  rtc(SDA, SCL);
//Initialize the LCD display using I2C
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS,NUM_CHARS,NUM_ROWS);   
Buttons * buttons =  new Buttons(LOAD_IN, CLOCK_ENABLE_PIN, CLOCK_IN_PIN, DATA_IN_PIN);
String alarmTime = "";
void setup() { 
  // Initialize the rtc object
  rtc.begin(); 
// The following lines can be uncommented to set the date and time 
//  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(11, 10, 2022);   // Set the date to January 1st, 2014 
  // Serial.begin(9600); 
  // Serial.println("Starting...");
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0,0); 
  lcd.print(rtc.getDOWStr());
  lcd.print(rtc.getDateStr()); 
  lcd.setCursor(0,1); 

} 

void loop() { 
  lcd.setCursor(0,1); 
  String currTime = rtc.getTimeStr(); 
  // Serial.println(rtc.getTimeStr());
  lcd.print(currTime);  
  if(currTime == alarmTime){
    alarmState();
  }
  byte pressedButtons = buttons->getButtonsPressed();
  // lcd.print(pressedButtons);

  if(pressedButtons == 128){ //if the clock set button is pressed 
    clockSetState();
  } 
  if(pressedButtons == 64){ //if the alarm set button is pressed 
    alarmSetState();
  } 
  delay(100);
}
 
void alarmState(){

} 

void clockSetState(){ 
  int hours = 0; 
  int minutes = 0; 
  lcd.clear();
  lcd.setCursor(3, 0);  
  lcd.print("Clock Set");  
  while(1){   
    byte pressedButtons = buttons->getButtonsPressed();
    if(pressedButtons == 1){
      break;
    }
    if(pressedButtons == 32){
      hours = (hours+1) % 24;
    } 
    if(pressedButtons == 16){ 
      if (minutes == 60){
        hours++;
      }
      minutes = (minutes+1) % 60;
    } 
    lcd.setCursor(3,1); 
    lcd.print(hours); 
    lcd.print(":"); 
    lcd.print(minutes);  
    delay(200);
  }
  rtc.setTime(hours, minutes, 0);

}

void alarmSetState(){

}  