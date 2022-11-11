#ifndef SpeakerH
#define SpeakerH    

class Speaker{
  public: 
    Speaker(int speakerPin); 
    void Ring(); 
  private: 
    int speakerPin; 
}; 

#endif