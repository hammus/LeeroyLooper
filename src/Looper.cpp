#include "Looper.h"
#include <iostream>
using namespace std;

void Looper::printDeviceInfo() {

    unsigned int deviceCount = rtAudio.getDeviceCount();

    RtAudio::DeviceInfo info;
    cout << "-------------------------------------------------------------------" << endl;
    for (unsigned int i = 0; i < deviceCount; ++i) {
        info = rtAudio.getDeviceInfo(i);

        if(info.probed == true) {
            cout << "Name: " << info.name << endl;
            cout << "Output Channels: " << info.outputChannels << endl;
            cout << "Input Channels: " << info.inputChannels << endl;
            cout << "Duplex Channels: " << info.duplexChannels << endl;
            cout << "Preferred Sample Rate: " << info.preferredSampleRate << endl;
            cout << "Available Sample Rates:" << endl;
            unsigned int sampleRateCount = info.sampleRates.size();
            for (unsigned int j = 0; j < sampleRateCount; ++j) {
                cout << "\t\t" << info.sampleRates[j] << "Hz" << endl; 
            }
            cout << "Default Output: " << ((info.isDefaultOutput) ? "Yes" : "No") << endl;
            cout << "Default Input: " << ((info.isDefaultInput) ? "Yes" : "No") << endl;

            cout << "-------------------------------------------------------------------" << endl;
        }
        

        
        
    }
}
