//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef TIME_MODULE_HPP
#define TIME_MODULE_HPP

#include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule {
public:
    TimeModule();
    ~TimeModule();
    TimeModule(TimeModule const &);

    TimeModule &operator=(TimeModule const &);

    std::string update();

    const std::string getFormatedTime() const;

private:
};


#endif //TimeModule_HPP
