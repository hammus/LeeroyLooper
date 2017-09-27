#include <iostream>
#include <RtAudio.h>

class Looper {
public:
    void printDeviceList();
    void printDeviceInfo(unsigned int idx);
    int findDevice(std::string deviceName);
private:
    RtAudio rtAudio;
    
};

