#include <LiquidCrystal_I2C.h>
#include <DS3231.h> 
#include "buttons.h"

#define NUM_CHARS 16 
#define NUM_ROWS 2
#define LCD_I2C_ADDRESS 0x27  
#define 

// Initialize the DS3231 real time clock (RTC)
DS3231  rtc(SDA, SCL);
//Initialize the LCD display using I2C
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS,NUM_CHARS,NUM_ROWS);  

void setup() { 
  // Initialize the rtc object
  rtc.begin(); 
// The following lines can be uncommented to set the date and time 
//  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(11, 10, 2022);   // Set the date to January 1st, 2014 
  
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
   lcd.print(rtc.getTimeStr());
   delay(20000);
}
