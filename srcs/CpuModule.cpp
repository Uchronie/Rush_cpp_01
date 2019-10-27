#include "CpuModule.hpp"

CpuModule::CpuModule() : _lastUpdate(time(NULL)) {
	this->init();
	this->_usage = 0;
	return ;
}

CpuModule::~CpuModule() {return ;}
CpuModule::CpuModule(CpuModule const &) {return ;}
CpuModule &CpuModule::operator=(CpuModule const &src) {
    return *this;
}

void CpuModule::update() {
	if (time(NULL) - this->_lastUpdate > 1)
		this->CpuUsage();
    return ;
}

double CpuModule::CpuUsage()
{
	mach_port_t host_port;
	host_cpu_load_info_data_t cpu_load;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	natural_t user, system, idle;
	host_port = mach_host_self();
	host_statistics(host_port, HOST_CPU_LOAD_INFO, (host_info_t)&cpu_load, &count);
	user = cpu_load.cpu_ticks[CPU_STATE_USER] - this->_prev_cpu_load.cpu_ticks[CPU_STATE_USER];
	system = cpu_load.cpu_ticks[CPU_STATE_SYSTEM] - this->_prev_cpu_load.cpu_ticks[CPU_STATE_SYSTEM];
	idle = cpu_load.cpu_ticks[CPU_STATE_IDLE] - this->_prev_cpu_load.cpu_ticks[CPU_STATE_IDLE];
	this->_usage = (double)(user + system) / (system + user + idle) * 100.0;
	std::cout << this->_usage << std::endl;

	this->_prev_cpu_load = cpu_load;
	this->_lastUpdate = time(NULL);

	return this->_usage;
}

void CpuModule::init() {
	//INITIALISATION USAGE
	mach_port_t host_port;
	mach_msg_type_number_t countUs = HOST_CPU_LOAD_INFO_COUNT;
	host_port = mach_host_self();
	host_statistics(host_port, HOST_CPU_LOAD_INFO, (host_info_t)&this->_prev_cpu_load, &countUs);

	//CPU NAME
	char CPUBrandString[0x40];
	unsigned int CPUInfo[4] = {0,0,0,0};

	__cpuid(0x80000000, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
	unsigned int nExIds = CPUInfo[0];

	memset(CPUBrandString, 0, sizeof(CPUBrandString));

	for (unsigned int i = 0x80000000; i <= nExIds; ++i)
	{
	    __cpuid(i, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);

	    if (i == 0x80000002)
	        memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
	    else if (i == 0x80000003)
	        memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
	    else if (i == 0x80000004)
	        memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}

	std::cout << "CPU Type: " << CPUBrandString << std::endl;
	this->_type = CPUBrandString;

	//CPU NB CORE
	int nm[2];
	size_t len = 4;
	uint32_t count;

	nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
	sysctl(nm, 2, &count, &len, NULL, 0);

	if (count < 1) {
		nm[1] = HW_NCPU;
		sysctl(nm, 2, &count, &len, NULL, 0);
		if (count < 1)
			count = 1;
 	}

	std::cout << "Number of core: " << count << std::endl;
	this->_core = count;
}
