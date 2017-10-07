#include "Looper.h"

int main() {

	Looper looper;
	int MyDevice = looper.findDeviceByName("Yamaha");
	std::cout << "Device Result: " << MyDevice << std::endl;
	char i = std::cin.get();
	return 0;

}