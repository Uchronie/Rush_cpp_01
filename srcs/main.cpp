//
// Created by Hippolyte Einfalt on 26/10/2019.
//



#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "UserModule.hpp"
#include "CpuModule.hpp"
#include "IMonitorDisplay.hpp"


int         main() {
    char        name[_SC_HOST_NAME_MAX];
		UserModule  mod = UserModule();
    TimeModule  time = TimeModule();
		OsModule   os = OsModule();
    CpuModule   cpu = CpuModule();

    gethostname(name, _SC_HOST_NAME_MAX);
		std::cout << "time : " << time.getFormatedTime() << std::endl;
    std::cout << "name : " << name << std::endl;
    std::cout << "host : " << mod.getHostInfo();
    std::cout << "user : " << mod.getUserInfo();
    std::cout << os.getOsInfo();

    return (0);
}
