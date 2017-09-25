#include "Looper.h"
#include <iostream>
using namespace std;

void Looper::printAvailableDevices() {

    unsigned int deviceCount = rtAudio.getDeviceCount();

    cout << "Test MAC Cleaned" << endl;

    RtAudio::DeviceInfo info;
    cout << "-------------------------------------------------------------------" << endl;
    for (unsigned int i = 0; i < deviceCount; ++i) {
        info = rtAudio.getDeviceInfo(i);

        if(info.probed == true) {
            cout << "Name: " << info.name << endl;
            cout << "Output Channels: " << info.outputChannels << endl;
            cout << "Input Channels: " << info.inputChannels << endl;
            cout << "Duplex Channels: " << info.duplexChannels << endl;
            cout << "-------------------------------------------------------------------" << endl;
        }

        
        
    }
}
