#ifndef ButtonsH
#define ButtonsH    

class Buttons{
    public: 
        Buttons(int loadPin, int clockEnablePin, int clockInPin, int dataInPin);  
        byte getButtonsPressed();
    private: 
    int loadPin;
    int clockEnablePin;
    int dataInPin;
    int clockInPin;
};
#endif