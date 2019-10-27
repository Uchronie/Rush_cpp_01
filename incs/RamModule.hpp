#ifndef RAM_MODULE_HPP
#define RAM_MODULE_HPP

#include "IMonitorModule.hpp"

class RamModule : public IMonitorModule {
public:
    RamModule();
    ~RamModule();
    RamModule(RamModule const &);

    RamModule &operator=(RamModule const &);

    std::string update();

	void RamUsage();
	std::string bytes_format(long bytes);

private:
	time_t _lastUpdate;
	std::string _print;
};


#endif //RamModule_HPP
