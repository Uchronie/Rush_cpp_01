//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "OsModule.hpp"

OsModule::OsModule() : _osInfo(initOsInfo()) {return ;}
OsModule::~OsModule() {return ;}
OsModule::OsModule(OsModule const &) : _osInfo(getOsInfo()) {return ;}
OsModule &OsModule::operator=(OsModule const &src) {
    _osInfo = src.getOsInfo();
    return *this;
}

void OsModule::update() {
    return ;
}

std::string       OsModule::initOsInfo() {
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

const std::string &OsModule::getOsInfo() const {
    return _osInfo;
}

void OsModule::setOsInfo(const std::string &osInfo) {
    _osInfo = osInfo;
}
