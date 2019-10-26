//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "TimeModule.hpp"

TimeModule::TimeModule() {return ;}
TimeModule::~TimeModule() {return ;}
TimeModule::TimeModule(TimeModule const &) {return ;}
TimeModule &TimeModule::operator=(TimeModule const &src) {
    return *this;
}

void TimeModule::update() {
    return ;
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
