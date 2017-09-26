#include <iostream>
#include <RtAudio.h>

/* REGEX Shite for later
#include <regex>

string pattern = "(.*)(Liam)(.*)";
regex rgx = regex(pattern, regex::ECMAScript | regex::icase);

if( regex_match(info.name, rgx) ) {
    cout << "*** Matched Device ***" << endl;
} else {
    cout << "No Match." << endl;

}
*/

class Looper {
public:
    void printDeviceList();
    void printDeviceInfo(unsigned int idx);
    int findDevice(std::string deviceName);
private:
    RtAudio rtAudio;
    
};

