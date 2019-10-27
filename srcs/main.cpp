//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

#include "SdlClass.hpp"
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
    SdlClass win;

    gethostname(name, _SC_HOST_NAME_MAX);
		std::cout << "time : " << time.getFormatedTime() << std::endl;
    std::cout << "name : " << name << std::endl;
    std::cout << "host : " << mod.getHostInfo();
    std::cout << "user : " << mod.getUserInfo();
    std::cout << os.getOsInfo();

    while (win.isRunning())
        win.update();
    return (0);
}
