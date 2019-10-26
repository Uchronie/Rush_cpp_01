//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef FT_GKRELLM_USERMODULE_HPP
#define FT_GKRELLM_USERMODULE_HPP

#include "IMonitorModule.hpp"

class UserModule : public IMonitorModule {
public:
    UserModule();
    ~UserModule();
    UserModule(UserModule const &);

    UserModule &operator=(UserModule const &);

    std::string initInfo(long uid) const;
    void update();

    const std::string &getHostInfo() const;
    void setHostInfo(const std::string &hostInfo);
    const std::string &getUserInfo() const;
    void setUserInfo(const std::string &userInfo);

private:
    std::string     _hostInfo;
    std::string     _userInfo;
};


#endif //FT_GKRELLM_USERMODULE_HPP
