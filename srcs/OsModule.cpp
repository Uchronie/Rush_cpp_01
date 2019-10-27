//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "OsModule.hpp"

OsModule::OsModule() {
	initOsInfo();
	return ;
}
OsModule::~OsModule() {return ;}
OsModule::OsModule(OsModule const &) {
	initOsInfo();
	return ;
}
OsModule &OsModule::operator=(OsModule const &src) {
    this->_print = src.getOsInfo();
    return *this;
}

void OsModule::update() {
    return ;
}

std::string       OsModule::initOsInfo() {
	std::string value = std::to_string(GetOSVersionComponent(1))+ "." +
	std::to_string(GetOSVersionComponent(2))+ "." + std::to_string(GetOSVersionComponent(3));

	this->_print = "MacOs version " + value;
	std::cout << this->_print << std::endl;
	return this->_print;
}

int OsModule::GetOSVersionComponent(int component) {
    char cmd[64] ;

    sprintf(cmd, "sw_vers -productVersion | awk -F '.' '{print $%d}'", component);
    FILE* stdoutFile = popen(cmd, "r") ;
    int answer = 0 ;
    if (stdoutFile) {
        char buff[16] ;
        char *stdout = fgets(buff, sizeof(buff), stdoutFile) ;
        pclose(stdoutFile) ;
        sscanf(stdout, "%d", &answer) ;
    }
    return answer ;
}

const std::string &OsModule::getOsInfo() const {
    return this->_print;
}

void OsModule::setOsInfo(const std::string &osInfo) {
    this->_print = osInfo;
}
