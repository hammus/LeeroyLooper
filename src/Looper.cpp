#include "Looper.h"
#include <iostream>
#include <regex>
using namespace std;

void Looper::printDeviceList()
{

    unsigned int deviceCount = rtAudio.getDeviceCount();

    RtAudio::DeviceInfo info;
    cout << "-------------------------------------------------------------------" << endl;
    for (unsigned int i = 0; i < deviceCount; ++i)
    {
        //Note for my C++ noobishness: requires arrow accessor here as this in C++ is a pointer
        this->printDeviceInfo(i);
    }
}

void Looper::printDeviceInfo(unsigned int idx)
{
    RtAudio::DeviceInfo info;
    info = rtAudio.getDeviceInfo(idx);

    if (info.probed == true)
    {
        cout << "Name: " << info.name << endl;
        cout << "Output Channels: " << info.outputChannels << endl;
        cout << "Input Channels: " << info.inputChannels << endl;
        cout << "Duplex Channels: " << info.duplexChannels << endl;
        cout << "Preferred Sample Rate: " << info.preferredSampleRate << endl;
        cout << "Available Sample Rates:" << endl;
        unsigned int sampleRateCount = info.sampleRates.size();
        for (unsigned int j = 0; j < sampleRateCount; ++j)
        {
            cout << "\t\t\t- " << info.sampleRates[j] << "Hz" << endl;
        }
        cout << "Default Output: " << ((info.isDefaultOutput) ? "Yes" : "No") << endl;
        cout << "Default Input: " << ((info.isDefaultInput) ? "Yes" : "No") << endl;

        cout << "-------------------------------------------------------------------" << endl;
    }
}

int Looper::findDeviceByName(std::string deviceName)
{

    unsigned int deviceCount = rtAudio.getDeviceCount();
    unsigned int foundDevice = -1;
    RtAudio::DeviceInfo info;

    for (unsigned int i = 0; i < deviceCount; ++i)
    {
        info = rtAudio.getDeviceInfo(i);
        string pattern = "(.*)(" + deviceName + ")(.*)";
        regex rgx = regex(pattern, regex::ECMAScript | regex::icase);
    
        if (regex_match(info.name, rgx))
        {
            cout << "*** Matched Device ***" << endl;
            this->printDeviceInfo(i);
            foundDevice = i;
            break;
        }
    }

    return foundDevice;
    
}
