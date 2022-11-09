#ifndef MotorsH
#define MotorsH

class Motors{
    public: 
        Motors(int LeftMotorForward, int LeftMotorBackward, int RightMotorForward, int RightMotorBackward); //2-pins per motor
        void moveForward();
        void moveBackward();
        void turnLeft();
        void turnRight(); 
        int getLeftMotorForward();
    private:
        //our L298N control pins
        int LeftMotorForward;
        int LeftMotorBackward;
        int RightMotorForward;
        int RightMotorBackward;
}; 

#endif