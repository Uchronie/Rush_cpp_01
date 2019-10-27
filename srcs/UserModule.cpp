//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "UserModule.hpp"

UserModule::UserModule() : _hostInfo(initInfo(gethostid())), _userInfo(initInfo(getuid())){return ;}

UserModule::~UserModule() {return ;}

UserModule::UserModule(UserModule const &src) : _hostInfo(src.getHostInfo()), _userInfo(src.getUserInfo()) {return ;}

UserModule &UserModule::operator=(UserModule const &src) {
    _hostInfo = src.getHostInfo();
    _userInfo = src.getUserInfo();
    return *this;
}

std::string UserModule::update() {
	std::string ret = "User : " + this->_userInfo + "\nHost : " + this->_hostInfo + "\n";
    return ret;
}


std::string UserModule::initInfo(long uid) const {
    std::stringstream ret;
    struct passwd *var;

    var = getpwuid(uid);
    ret << var->pw_name << '-' << var->pw_gid << '-' << var->pw_uid;
		return ret.str();
}

const std::string &UserModule::getHostInfo() const {return _hostInfo;}
void UserModule::setHostInfo(const std::string &hostInfo) {_hostInfo = hostInfo;}
const std::string &UserModule::getUserInfo() const {return _userInfo;}
void UserModule::setUserInfo(const std::string &userInfo) {_userInfo = userInfo;}
