#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

# include <ncurses.h>
# include <curses.h>
# include <iostream>
# include <string>
# include <list>
# include <pwd.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <sys/types.h>
# include <sys/utsname.h>
# include <sys/param.h>
# include <sys/sysctl.h>
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <cpuid.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

class IMonitorModule {
public:
    IMonitorModule() {}
    virtual ~IMonitorModule() {}

    virtual std::string update() = 0;
private:
    IMonitorModule(IMonitorModule const &);
    IMonitorModule &operator=(IMonitorModule const &);
};

#endif
