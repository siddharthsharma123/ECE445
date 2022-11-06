#ifndef UltrasonicsH
#define UltrasonicsH   
#include "NewPing.h" 
#include "Vector.h"


using namespace std;

class Ultrasonics{
    public:  
        Ultrasonics(int LeftUltrasonicPin, int MidUltrasonicPin, int RightUltrasonicPin); 
        float * Scan();   
        float getLeftDist(); //centimeteres 
        float getRightDist(); 
        float getMidDist(); 
    private: 
        NewPing * sonarLeft; 
        NewPing * sonarMid; 
        NewPing  * sonarRight;   
};
#endif
