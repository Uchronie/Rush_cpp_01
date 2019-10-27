#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay {
public:
	IMonitorDisplay() {}
	virtual ~IMonitorDisplay() {}

	virtual void display() = 0;

private:
	std::list<IMonitorModule*> _mods;

};

#endif
