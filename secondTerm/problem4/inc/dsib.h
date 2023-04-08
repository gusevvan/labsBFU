#pragma once
#include <iostream>
#include <device.h>

namespace smart {
	class DSIB : public Device {
	protected:
		int _curSignal = 0;
	public:
		void updateSignal(int value) {
			_curSignal = value;
		}
		void showCurSignal() {
			std::cout << _curSignal << "\n";
		}
	};

	class RealLab : public DSIB {
	public:
		RealLab(int key, Mode mode, std::string info) {
            _type = "Discrete signal input block";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Discrete signal input block RealLab NL-16HV ";
			out();
			showCurSignal();
		}
	};

	class PriborElectro : public DSIB {
	public:
		PriborElectro(int key, Mode mode, std::string info) {
            _type = "Discrete signal input block";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << "Discrete signal input block PriborElectro PRE-16 ";
			out();
			showCurSignal();
		}
	};

	class EnergoService : public DSIB {
	public:
		EnergoService(int key, Mode mode, std::string info) {
            _type = "Discrete signal input block";
			_key = key;
			_mode = mode;
			_addInfo = info;
		}
		void poll() override {
			std::cout << _type << " EnergoService ENMV-1-24 ";
			out();
			showCurSignal();
		}
	};
}
