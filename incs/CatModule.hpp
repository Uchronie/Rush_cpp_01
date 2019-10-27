#ifndef CAT_MODULE_HPP
#define CAT_MODULE_HPP

#include "IMonitorModule.hpp"

class CatModule : public IMonitorModule {
public:
    CatModule();
    ~CatModule();
    CatModule(CatModule const &);

    CatModule &operator=(CatModule const &);

    std::string update();
};


#endif //CatModule_HPP
