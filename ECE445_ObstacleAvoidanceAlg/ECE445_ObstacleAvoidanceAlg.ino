
#include "motors.h" 
#include "ultrasonics.h" 


#define LEFT_MOTOR_FORWARD_PIN 4 
#define LEFT_MOTOR_BACKWARD_PIN 0  
#define RIGHT_MOTOR_FORWARD_PIN 6 
#define RIGHT_MOTOR_BACKWARD_PIN 7 
#define ULTRASONIC_LEFT_PIN 8 
#define ULTRASONIC_MID_PIN 9 
#define ULTRASONIC_RIGHT_PIN 10 
#define MAX_DISTANCE 400.0



void setup(){
  pinMode(LEFT_MOTOR_FORWARD_PIN, OUTPUT); 
  pinMode(LEFT_MOTOR_BACKWARD_PIN, OUTPUT); 
  pinMode(RIGHT_MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("test breh");
} 
Ultrasonics * sensorsArray = new Ultrasonics(ULTRASONIC_LEFT_PIN, ULTRASONIC_MID_PIN, ULTRASONIC_RIGHT_PIN); 
Motors * motorDriver = new Motors(LEFT_MOTOR_FORWARD_PIN, LEFT_MOTOR_BACKWARD_PIN, RIGHT_MOTOR_FORWARD_PIN, RIGHT_MOTOR_BACKWARD_PIN);
void loop(){ 
  float distance[3]; //This array holds all the distances ; 
  sensorsArray->Scan(distance);
}
