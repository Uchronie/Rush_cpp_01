#include "RamModule.hpp"

RamModule::RamModule() : _lastUpdate(time(NULL)) {
	return ;
}

RamModule::~RamModule() {return ;}
RamModule::RamModule(RamModule const &) {return ;}
RamModule &RamModule::operator=(RamModule const &src) {
    return *this;
}

void RamModule::update() {
	if (time(NULL) - this->_lastUpdate > 1)
		this->RamUsage();

    return ;
}

std::string RamModule::bytes_format(long bytes) {
	static const std::string s[] = {"bytes", "Kb", "Mb", "Gb", "Tb", "Eb"};
	long double b = bytes;
	int i = 0;
	for (i = 0; b >= 1024 && i < 6; i++)
		b /= 1024;
	std::stringstream ss;
	ss << std::setprecision((i == 0 ? 0 : 2)) << std::fixed << b << " " << s[i];
	return ss.str();
}

void RamModule::RamUsage()
{
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,(host_info64_t)&vm_stats, &count))
    {
        long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
        long long used_memory = ((int64_t)vm_stats.active_count +
                                 (int64_t)vm_stats.inactive_count +
                                 (int64_t)vm_stats.wire_count) *  (int64_t)page_size;

		std::stringstream ret;
		ret << this->bytes_format(used_memory) << "M used, " << this->bytes_format(free_memory) << "M unused." << std::endl;
        this->_print = ret.str();

		std::cout << this->_print;
		this->_lastUpdate = time(NULL);

	}

}
