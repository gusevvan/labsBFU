#pragma once
#include <iostream>
#include <device.h>

namespace smart {

	class EM : public Device {
	protected:
		double _energyCounter = 0;
	public:
		void updateCounter(double value) {
			_energyCounter = value;
		}
		void showCounter() {
			std::cout << _energyCounter << "kW\n";
		}
	};

	class Mercury : public EM {
	public:
		Mercury(int key, Mode mode, std::string info) {
            _type = "Electricity Meter";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Electricity Meter Mercury 230 ";
			out();
			showCounter();
		}
	};

	class Neva : public EM {
	public:
		Neva(int key, Mode mode, std::string info) {
            _type = "Electricity Meter";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Electricity Meter Neva MT314 ";
			out();
			showCounter();
		}
	};

	class EnergoMera : public EM {
	public:
		EnergoMera(int key, Mode mode, std::string info) {
            _type = "Electricity Meter";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Electricity Meter EnergoMera CE308 ";
			out();
			showCounter();
		}
	};
}