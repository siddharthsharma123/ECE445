#ifndef ButtonsH
#define ButtonsH    

class Buttons{
    public: 
        Buttons(int loadPin, int clockEnablePin, int clockInPin, int dataInPin);  
        byte getButtonsPressed(); //Doesn't include delay
    private: 
    int loadPin;
    int clockEnablePin;
    int dataInPin;
    int clockInPin;
};
#endif