#ifndef NCURSES_DISPLAY_HPP
# define NCURSES_DISPLAY_HPP
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class NcursesDisplay : public IMonitorDisplay {
public:
	NcursesDisplay();
	NcursesDisplay(NcursesDisplay const &);
	~NcursesDisplay();
	NcursesDisplay &operator=(NcursesDisplay const &);

	void display();
private:
	std::list<IMonitorModule*> _mods;

};

#endif
