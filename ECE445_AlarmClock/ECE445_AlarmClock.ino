#include <LiquidCrystal_I2C.h>
#include <DS3231.h>  
#include "buttons.h"  
#include "speaker.h" 
#include "motors.h"

//Pin out definitions
#define NUM_CHARS 16 //LCD values 
#define NUM_ROWS 2 
#define LCD_I2C_ADDRESS 0x27  
#define CLOCK_ENABLE_PIN 4 //shift register values
#define DATA_IN_PIN 5 
#define CLOCK_IN_PIN 6
#define LOAD_IN 7 
#define SPEAKER_PIN 2 //speaker output  
#define LEFT_MOTOR_FORWARD A0 //Motor Pins
#define LEFT_MOTOR_BACKWARD A1 
#define RIGHT_MOTOR_FORWARD A2 
#define RIGHT_MOTOR_BACKWARD A3
#define CLOCK_SET_STATE 1 //button vector values
#define ALARM_SET_STATE 8    
#define ENTER_BUTTON 128
#define HRS_INCREMENT 4  
#define MIN_INCREMENT 96  
#define ONES_INCREMENT 16 
#define TEN_INCREMENT 96 
#define HUN_INCREMENT 2
#define RAND_SEED A1 //Random Number Seed pin

using namespace std;

Speaker * speaker = new Speaker(SPEAKER_PIN); //Initializing the piezo buzzer
DS3231  rtc(SDA, SCL); // Initialize the DS3231 real time clock (RTC)
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS,NUM_CHARS,NUM_ROWS);//Initialize the LCD display using I2C 
Motors * motors = new Motors(LEFT_MOTOR_FORWARD,LEFT_MOTOR_BACKWARD,RIGHT_MOTOR_FORWARD, RIGHT_MOTOR_BACKWARD); 
Buttons * buttons =  new Buttons(LOAD_IN, CLOCK_ENABLE_PIN, CLOCK_IN_PIN, DATA_IN_PIN); //Initializing buttons from shift reg
int alarmTime[2] = {0,0}; //Alarm variables 
bool alarmArmed = false; 
String alarmTimeString = "";  

void setup() { 
  // Initialize the rtc object
  rtc.begin();  
  pinMode(SPEAKER_PIN,OUTPUT);  
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);  
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT); 
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT); 
  digitalWrite(SPEAKER_PIN, HIGH);  
  randomSeed(analogRead(RAND_SEED));     
  lcd.init();
  lcd.clear();
  lcd.backlight();
} 

void loop() {  
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("EarlyBirds Meow");
  String currTime = rtc.getTimeStr();   
  lcd.setCursor(0,1); 
  lcd.print(rtc.getTimeStr()); 
  if(alarmArmed){ 
    lcd.setCursor(15,1);  
    lcd.print(char(255)); //Setting alarm "on" indicator
  }
  String hoursMinutes = currTime.substring(0,5); //getting the hours and minutes out of the current time string
  if(hoursMinutes.equals(alarmTimeString) && alarmArmed){
    alarmState();
  }
  byte pressedButtons = buttons->getButtonsPressed();
  if(pressedButtons == CLOCK_SET_STATE){ //if the clock set button is pressed 
    clockSetState();
  } 
  if(pressedButtons == ALARM_SET_STATE){ 
    alarmSetState();
  } 
  delay(100);
}
 
void alarmState(){   
  //Setting up the math equation that the user has to solve in order to turn the alarm off
  int operand1 = random(100); 
  int operand2 = random(100); 
  int sum = operand1 + operand2; 
  int userAnswer = 0;
  speaker->Ring();  
  motors->moveForward();
  while(alarmArmed){ 
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("Alarm Triggered");   
    lcd.setCursor(0,1); 
    lcd.print(operand1); 
    lcd.print(" + ");
    lcd.print(operand2); 
    lcd.print(" = ");
    byte pressedButtons = buttons->getButtonsPressed(); 
    if(pressedButtons == ONES_INCREMENT){
      userAnswer += 1;
    } 
    if(pressedButtons == TEN_INCREMENT){
      userAnswer += 10; 
    } 
    if(pressedButtons == HUN_INCREMENT){ 
      userAnswer += 100;
    } 
    userAnswer = userAnswer % 1000;  
    lcd.print(userAnswer);
    if(userAnswer == sum){
      alarmArmed = false; 
      break;
    } 
    delay(300);
  } 
  speaker->Quiet(); 
  motors->stopMotors();
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("DONT FUCKING"); 
  lcd.setCursor(5,1); 
  lcd.print("SLEEP!"); 
  delay(3000); 
  lcd.clear();  
} 

void clockSetState(){ 
  int hours = 0; 
  int minutes = 0; 
  lcd.clear();
  lcd.setCursor(3, 0);  
  lcd.print("Clock Set");  
  while(1){   
    byte pressedButtons = buttons->getButtonsPressed();
    if(pressedButtons == ENTER_BUTTON){
      break;
    }
    if(pressedButtons == HRS_INCREMENT){
      hours = (hours+1) % 24;
    } 
    if(pressedButtons == MIN_INCREMENT){ 
      if (minutes == 60){
        hours = (hours+1) % 24;
      }
      minutes = (minutes+1) % 60;
    } 
    lcd.setCursor(3,1);  
    if(hours < 10){
      lcd.print(0);
    }
    lcd.print(hours); 
    lcd.print(":");  
    if(minutes < 10){
      lcd.print(0);
    }
    lcd.print(minutes);  
    delay(200); 
  }
  rtc.setTime(hours, minutes, 0); 
  lcd.clear();
}

void alarmSetState(){  
  while(1){
    lcd.clear(); 
    lcd.setCursor(0,0); 
    lcd.print("1: Edit Alarm ");  
    lcd.setCursor(0, 1);
    lcd.print("2: Alarm On"); 
    delay(1000);  
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("4: Alarm Off"); 
    if(buttons->getButtonsPressed() == 1){
      editAlarm(); 
      break;
    } 
    else if(buttons->getButtonsPressed() == 6){
      disarmAlarm(); 
      break;
    } 
    else if(buttons->getButtonsPressed() == 16){
      armAlarm(); 
      break;     
    }
  }

}   

void editAlarm(){ 
  
  while(1){ 
    lcd.clear(); 
    lcd.setCursor(3,0);
    lcd.print("Edit Alarm"); 
    if(buttons->getButtonsPressed() == HRS_INCREMENT){
      alarmTime[0] =  (alarmTime[0]+1) % 24; // setting the alarm's hour
    } 
    if(buttons->getButtonsPressed() == MIN_INCREMENT){ 
      if(alarmTime[1] == 60){ //if the minutes reach 60, increment the hour
        alarmTime[0]++;
        alarmTime[0] =  (alarmTime[0]+1) % 24; 
      }
      alarmTime[1] =  (alarmTime[1]+1) % 60; //setting the alarm's minute
    }  
    lcd.setCursor(3,1);
    if(alarmTime[0] < 10){
      lcd.print(0);
    } 
    lcd.print(alarmTime[0]);  
    lcd.print(":");
    if(alarmTime[1] < 10){
      lcd.print(0);    
    } 
    lcd.print(alarmTime[1]);  
    if(buttons->getButtonsPressed() == ENTER_BUTTON){
      armAlarm();  
      String hoursZero = ""; 
      String minutesZero = "";
      if(alarmTime[0] < 10){
        hoursZero = "0";
      } 
      if(alarmTime[1] < 10){
        minutesZero = "0";
      } 
      alarmTimeString = hoursZero + String(alarmTime[0]) + ":" + minutesZero + String(alarmTime[1]); //converting alarm time to a string     
      break;
    }
  }
} 

void disarmAlarm(){
  alarmArmed = false;
} 

void armAlarm(){ 
  alarmArmed = true;
}