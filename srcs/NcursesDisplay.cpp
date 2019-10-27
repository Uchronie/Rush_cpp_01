#include "NcursesDisplay.hpp"
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "UserModule.hpp"
#include "CatModule.hpp"
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
	this->_mods.push_back(new CatModule());
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
	std::string ret;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	WINDOW *win[_mods.size()];
	for (size_t i = 0; i < _mods.size(); i++)
		win[i] = newwin(6, COLS, i * 6, 0);

	int n = 0;
	while (1) {
		for (it = _mods.begin(); it != _mods.end(); ++it) {
			if (it != _mods.end()) {
				wclear(win[n]);
				box(win[n], ACS_VLINE, ACS_HLINE);
				int i = 0;
			    std::stringstream s((*it)->update());
			    std::string output;
			    while (!s.eof())
			    {
			        getline(s, output);
			        mvwprintw(win[n], 1 + i, 1, output.c_str());
			        i++;
			    }
				n++;
			}
		}

		for (size_t i = 0; i < _mods.size(); i++)
			wrefresh(win[i]);

		timeout(100);
		input = getch();
		if (input == 27) {
			break;
		}
		n = 0;
	}

	for (size_t i = 0; i < _mods.size(); i++)
		delwin(win[i]);
	endwin();
}
