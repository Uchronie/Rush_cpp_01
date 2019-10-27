#ifndef NETWORK_MODULE_HPP
#define NETWORK_MODULE_HPP

#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule {
public:
    NetworkModule();
    ~NetworkModule();
    NetworkModule(NetworkModule const &);

    NetworkModule &operator=(NetworkModule const &);

    void update();

	void init();
	void NetworkUsage();
	std::string bytes_format(long bytes);

private:
	time_t _lastUpdate;
	std::string _print;
};


#endif //NetworkModule_HPP
