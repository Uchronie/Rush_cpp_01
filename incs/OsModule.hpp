//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef OS_MODULE_HPP
#define OS_MODULE_HPP

#include "IMonitorModule.hpp"

class OsModule : public IMonitorModule {
public:
    OsModule();
    ~OsModule();
    OsModule(OsModule const &);

    OsModule &operator=(OsModule const &);

    void update();
    std::string       initOsInfo();

    const std::string &getOsInfo() const;
    void setOsInfo(const std::string &osInfo);
	int GetOSVersionComponent(int component);

private:
    std::string     _print;
};


#endif //OsModule_HPP
