//
// Created by Hippolyte Einfalt on 26/10/2019.
//
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "UserModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "IMonitorDisplay.hpp"
#include "NcursesDisplay.hpp"

int         main(int ac, char **av) {
	if (ac > 1 && static_cast<std::string>(av[1]) == "noGui") {
		NcursesDisplay nc;
		nc.display();
	}

    return (0);
}
