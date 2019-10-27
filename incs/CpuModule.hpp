#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP

#include "IMonitorModule.hpp"

class CpuModule : public IMonitorModule {
public:
    CpuModule();
    ~CpuModule();
    CpuModule(CpuModule const &);

    CpuModule &operator=(CpuModule const &);

    std::string update();

	void init();
	double CpuUsage();
private:
	int _core;
	std::string _type;
	std::string _print;

	time_t _lastUpdate;
	double _usage;
	host_cpu_load_info_data_t _prev_cpu_load;
};


#endif //CpuModule_HPP
