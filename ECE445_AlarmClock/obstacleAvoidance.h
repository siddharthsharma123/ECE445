#ifndef ObstacleAvoidanceH
#define ObstacleAvoidanceH
#include "motors.h"
#include "ultrasonics.h"
#include "buttons.h"


class ObstacleAvoidance {
    public:
        // constructor for motors + sensors - this is the entire obstacle avoidance object
        ObstacleAvoidance(Motors * motorDriver, Ultrasonics * sensors, Buttons * buttonObj);

        // main function
        void navigate();

    private:
        // our motors, ultrasonics, buttons objects
        Motors * motorDriver;
        Ultrasonics * sensors;
        Buttons * buttonObj;
}






