#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <string>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <sstream>

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