#include <iostream>
#include <RtAudio.h>
#include <regex>
using namespace std;

int main() {

    RtAudio audio;
    size_t deviceCount = audio.getDeviceCount();

    cout << "-------------------------------------------------------------------" << endl;

    string pattern = "(.*)(Liam)(.*)";
    regex rgx = regex(pattern, regex::ECMAScript | regex::icase);

    RtAudio::DeviceInfo info;
    for (int i = 0; i < deviceCount; ++i) {
        info = audio.getDeviceInfo(i);

        if(info.probed == true) {
            cout << "Name: " << info.name << endl;
            cout << "Output Channels: " << info.outputChannels << endl;
            cout << "Input Channels: " << info.inputChannels << endl;
            cout << "Duplex Channels: " << info.duplexChannels << endl;
            if( regex_match(info.name, rgx) ) {
                cout << "*** Matched Device ***" << endl;
            } else {
                cout << "No Match." << endl;
    
            }
            cout << "-------------------------------------------------------------------" << endl;
        }

        
        
    }
}