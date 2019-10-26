//
// Created by Hippolyte Einfalt on 26/10/2019.
//


#include "../incs/UserModule.hpp"
#include "../incs/OsMonitor.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>


int         main() {
    char        name[_SC_HOST_NAME_MAX];
    UserModule  mod = UserModule();
    OsMonitor   os = OsMonitor();

    gethostname(name, _SC_HOST_NAME_MAX);
    std::cout << name << std::endl;
    std::cout << mod.getHostInfo();
    std::cout << mod.getUserInfo();
    std::cout << os.getOsInfo();

    return (0);
}

