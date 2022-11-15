// Ultrasonics * sensorsArray = new Ultrasonics(ULTRASONIC_LEFT_PIN, ULTRASONIC_MID_PIN, ULTRASONIC_RIGHT_PIN); 
// Motors * motorDriver = new Motors(LEFT_MOTOR_FORWARD_PIN, LEFT_MOTOR_BACKWARD_PIN, RIGHT_MOTOR_FORWARD_PIN, RIGHT_MOTOR_BACKWARD_PIN);
// void loop(){ 
//   float distance[3]; //This array holds all the distances ; 
//   sensorsArray->Scan(distance); //get distances infront of each ulrtasonic 
//   motorDriver->moveForward();
// }

#include <Arduino.h>
#include "obstacleAvoidance.h"


using namespace std;


ObstacleAvoidance::ObstacleAvoidance(Motors * motorDriver, Ultrasonics * sensors, Buttons * button_obj) {
            this->motorDriver = motorDriver;
            this->sensors = sensors;
            this->buttonObj = &button_obj;
}


void ObstacleAvoidance::navigate(Motors * motorDriver, Ultrasonics * sensors, Button * button) {
    ObstacleAvoidance * obstacle_avoidance = new ObstacleAvoidance(&motorDriver, &sensors, &button);
    Buttons * buttonVec = obstacle_avoidance->buttonObj;
    byte buttons_vec = buttonVec->getButtonsPressed();

    
    // check for values in range 0-15 -> indicates either enter, 1s, 10s, or 100s pressed -  in this case we would return
    if(buttons_vec > = 0 && buttons_vec < 16) {
        return;
    }

    // otherwise we would continue our naviagtion process
    float distance_arr[3];
    // fill the array with scanned values
    sensors->Scan(&distance_arr);


    // pick max distance_arr val, and then turn that direction - for now, we'll take max of right and left scans, and then compare that with 
    // the middle direction

    float max_dist = 0.0;
    max_dist = max(distance_arr[0], distance_arr[2]);
    // if either of the sides read a higher distance measurement, then we want to turn that way
    
    // if the middle distance is already less than 20, we should move backwards.
    if(distance_arr[1] < 20.0) {
        motorDriver->moveBackward();
    }
    
    if(max_dist > distance_arr[1]) {
        if(max_dist == distance_arr[0]) {
            motorDriver->turnLeft();
        }
        else {
            motorDriver->turnRight;
        }
    }

    motorDriver->moveForward();

}