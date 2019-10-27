//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP

#include "IMonitorModule.hpp"

class CpuModule : public IMonitorModule {
public:
    CpuModule();
    ~CpuModule();
    CpuModule(CpuModule const &);

    CpuModule &operator=(CpuModule const &);

    void update();

		void init();
private:
		int _core;
		std::string _type;
};


#endif //CpuModule_HPP
