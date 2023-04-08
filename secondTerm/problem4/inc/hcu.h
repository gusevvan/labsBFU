#pragma once
#include <iostream>
#include <device.h>

namespace smart {
	class HCU : public Device {
	protected:
		short _temperature = 0;
	public:
		void changeTemperature(short temperature) {
			_temperature = temperature;
		}
		void showTemperature() {
			std::cout << _temperature << "°C\n";
		}
	};

	class Ouman : public HCU {
	public:
		Ouman(int key, Mode mode, std::string info) {
            _type = "Heating control unit";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Heating control unit Ouman S203 ";
			out();
			showTemperature();
		}
	};

	class Oven : public HCU {
	public:
		Oven(int key, Mode mode, std::string info) {
            _type = "Heating control unit";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Heating control unit Oven TPM232 ";
			out();
			showTemperature();
		}
	};
}
