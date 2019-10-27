#include "NcursesDisplay.hpp"
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "UserModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

NcursesDisplay::NcursesDisplay() {
	this->_mods.push_back(new TimeModule());
	this->_mods.push_back(new UserModule());
	this->_mods.push_back(new OsModule());
	this->_mods.push_back(new CpuModule());
	this->_mods.push_back(new RamModule());
	this->_mods.push_back(new NetworkModule());
	return ;
}

NcursesDisplay::~NcursesDisplay() {
	this->_mods.clear();
	return ;
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &) {
	//this->_mods = src._mods;
	return ;
}

NcursesDisplay &NcursesDisplay::operator=(NcursesDisplay const &) {
    //this->_mods = src._mods;
    return *this;
}

void NcursesDisplay::display() {
	std::list<IMonitorModule*>::iterator it;
	int input;
	initscr();
	noecho();
	cbreak();
	while (1) {
		clear();
		for (it = _mods.begin(); it != _mods.end(); ++it) {
			if (it != _mods.end())
				printw((*it)->update().c_str());
		}

		refresh();
		timeout(100);
		input = getch();
		if (input == 27) {
			break;
		}
	}
	endwin();
}
