#pragma once
#include <iostream>
#include <string>

namespace smart {

	enum Mode {OFF, ON};

	class Device {
	protected:
		int _key;
		Mode _mode;
		std::string _addInfo;
        std::string _type;
	public:
		virtual void poll() {}
		void out() {
			std::cout << _key << ": ";
			if (_mode == ON) {
				std::cout << "ON ";
			} else {
				std::cout << "OFF ";
			}
		}
		void changeMode() {
			if (_mode == ON) {
				_mode = OFF;
			} else {
				_mode = ON;
			}
		};
		void changeAddInfo(std::string info) {
			_addInfo = info;
		}
	};

}