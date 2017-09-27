#include "Looper.h"

int main() {

    Looper looper;

    looper.printDeviceList();
    int MyDevice = looper.findDevice("Scarlett");
    std::cout << "Device Result: " << MyDevice << std::endl;
    return 0;
   
}