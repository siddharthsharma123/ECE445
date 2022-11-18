#ifndef SpeakerH
#define SpeakerH    

class Speaker{
  public: 
    Speaker(int speakerPin); 
    void Ring(); 
    void Quiet();
  private: 
    int speakerPin; 
}; 

#endif