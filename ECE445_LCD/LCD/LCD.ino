#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

// Init the DS3231 RTC using the hardware interface
DS3231  rtc(SDA, SCL);

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);


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
  lcd.print("HI");

}

void loop() { 
   lcd.setCursor(0,1);
   lcd.print(rtc.getTimeStr());
   delay(1000);
}
