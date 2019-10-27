#include "NetworkModule.hpp"

NetworkModule::NetworkModule() : _lastUpdate(time(NULL)) {
	return ;
}

NetworkModule::~NetworkModule() {return ;}
NetworkModule::NetworkModule(NetworkModule const &) {return ;}
NetworkModule &NetworkModule::operator=(NetworkModule const &) {
    return *this;
}

std::string NetworkModule::update() {
	if (time(NULL) - this->_lastUpdate > 1)
		this->NetworkUsage();

    return this->_print;
}

std::string NetworkModule::bytes_format(long bytes) {
	static const std::string s[] = {"bytes", "Kb", "Mb", "Gb", "Tb", "Eb"};
	long double b = bytes;
	int i = 0;
	for (i = 0; b >= 1024 && i < 6; i++)
		b /= 1024;
	std::stringstream ss;
	ss << std::setprecision((i == 0 ? 0 : 2)) << std::fixed << b << " " << s[i];
	return ss.str();
}

void NetworkModule::NetworkUsage()
{
	FILE *f = popen("netstat -w1", "r");
	if (!f)
        return ;
	char buf[4096];
	long input = 0;
    long output = 0;
	while (fgets(buf, 4096, f) != NULL)
    {
        std::string line(buf);
		if (line.compare(0, 17, "            input") == 0 || line.compare(0, 10, "   packets") == 0)
            continue;
		long a;
        std::stringstream ss(line);
		ss >> a; // packets
        ss >> a; // errs
        ss >> input; // bytes
        ss >> a; // packets
        ss >> a; // errs
        ss >> output; // bytes

		std::stringstream ss2;

		ss2 << "Network packets : " << bytes_format(input);
        ss2 << "/s in, ";
        ss2 << bytes_format(output);
        ss2 << "/s out\n";
		this->_print = ss2.str();
		return;
    }

}
