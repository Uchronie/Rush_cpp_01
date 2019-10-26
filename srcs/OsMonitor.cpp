//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "../incs/OsMonitor.hpp"

OsMonitor::OsMonitor() : _osInfo(initOsInfo()) {return ;}
OsMonitor::~OsMonitor() {return ;}
OsMonitor::OsMonitor(OsMonitor const &) : _osInfo(getOsInfo()) {return ;}
OsMonitor &OsMonitor::operator=(OsMonitor const &src) {
    _osInfo = src.getOsInfo();
    return *this;
}

void OsMonitor::update() {
    return ;
}

std::string       OsMonitor::initOsInfo() {
    std::stringstream ret;
    struct utsname tmp;

    if (!uname(&tmp)) {//protect it later with exception
        ret << tmp.sysname << "\n" << tmp.nodename << "\n" << tmp.release << "\n" << tmp.version << "\n" << tmp.machine
            << std::endl;
        return ret.str();
    }
    else
        return "";
}

const std::string &OsMonitor::getOsInfo() const {
    return _osInfo;
}

void OsMonitor::setOsInfo(const std::string &osInfo) {
    _osInfo = osInfo;
}
