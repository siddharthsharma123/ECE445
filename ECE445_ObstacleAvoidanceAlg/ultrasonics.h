#ifndef UltrasonicsH
#define UltrasonicsH   
#include "NewPing.h" 
#include "Vector.h"
#define NUM_SENSORS 3

using namespace std;

class Ultrasonics{
    public:  
        Ultrasonics(int LeftUltrasonicPin, int MidUltrasonicPin, int RightUltrasonicPin);  
        float getLeftDist(void); //centimeteres 
        float getRightDist(); 
        float getMidDist();   
//        float getDist();
        void Scan(float (&distance)[NUM_SENSORS]); //Fires every sensor in the array and stores its distance
    private: 
        NewPing * sonarLeft; 
        NewPing * sonarMid; 
        NewPing  * sonarRight;   
};
#endif
