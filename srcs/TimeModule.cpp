//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "TimeModule.hpp"

TimeModule::TimeModule() {return ;}
TimeModule::~TimeModule() {return ;}
TimeModule::TimeModule(TimeModule const &) {return ;}
TimeModule &TimeModule::operator=(TimeModule const &) {
    return *this;
}

std::string TimeModule::update() {
    return (getFormatedTime() + "\n");
}

const std::string TimeModule::getFormatedTime() const {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,80,"%c.",timeinfo);
	return buffer;
}
