//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "CpuModule.hpp"

CpuModule::CpuModule() {
	this->init();
	return ;}
CpuModule::~CpuModule() {return ;}
CpuModule::CpuModule(CpuModule const &) {return ;}
CpuModule &CpuModule::operator=(CpuModule const &src) {
    return *this;
}

void CpuModule::update() {
    return ;
}

void CpuModule::init() {
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
