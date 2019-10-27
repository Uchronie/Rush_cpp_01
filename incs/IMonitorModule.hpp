#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

# include <iostream>
# include <string>
# include <sys/types.h>
# include <sys/utsname.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <sstream>
# include <ctime>
# include <cpuid.h>
# include <sys/param.h>
# include <sys/sysctl.h>

class IMonitorModule {
public:
    IMonitorModule() {}
    virtual ~IMonitorModule() {}

    virtual void update() = 0;
private:
    IMonitorModule(IMonitorModule const &);
    IMonitorModule &operator=(IMonitorModule const &);
};

#endif
