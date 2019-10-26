//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef OSMONITOR_HPP
#define OSMONITOR_HPP

#include "IMonitorModule.hpp"
#include <sys/utsname.h>

class OsMonitor : public IMonitorModule {
public:
    OsMonitor();
    ~OsMonitor();
    OsMonitor(OsMonitor const &);

    OsMonitor &operator=(OsMonitor const &);

    void update();
    std::string       initOsInfo();

    const std::string &getOsInfo() const;
    void setOsInfo(const std::string &osInfo);

private:
    std::string     _osInfo;
};


#endif //OSMONITOR_HPP
