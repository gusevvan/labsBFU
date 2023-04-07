#include <fstream>
#include <vector>
#include <device.h>
#include <em.h>
#include <dsib.h>
#include <hcu.h>

int main()
{
	std::ifstream in("input.txt");
	std::vector<smart::Device*> devices;
	std::string deviceName;
	while (in >> deviceName) {
		std::cout << deviceName;
		if (deviceName == "Mercury") {
			smart::Device* current = new smart::Mercury(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "Neva") {
			smart::Device* current = new smart::Neva(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "EnergoMera") {
			smart::Device* current = new smart::EnergoMera(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "RealLab") {
			smart::Device* current = new smart::RealLab(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "PriborElectro") {
			smart::Device* current = new smart::PriborElectro(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "EnergoService") {
			smart::Device* current = new smart::EnergoService(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "Ouman") {
			smart::Device* current = new smart::Ouman(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
		if (deviceName == "Oven") {
			smart::Device* current = new smart::Oven(devices.size(), smart::OFF, "");
			devices.push_back(current);
		}
	}
	for (auto device:devices) {
		device->poll();
	}
}
