//
// Created by Hippolyte Einfalt on 26/10/2019.
//
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "UserModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"
#include "IMonitorDisplay.hpp"

int GetOSVersionComponent(int component) {
    char cmd[64] ;

    sprintf(
            cmd,
            "sw_vers -productVersion | awk -F '.' '{print $%d}'",
            component
    ) ;
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


uint64_t rdtsc(void)
{
   uint32_t ret0[2];
   __asm__ __volatile__("rdtsc" : "=a"(ret0[0]), "=d"(ret0[1]));
   return ((uint64_t)ret0[1] << 32) | ret0[0];
}

int         main() {
    char        name[_SC_HOST_NAME_MAX];
	UserModule  mod = UserModule();
    TimeModule  time = TimeModule();
	OsModule   os = OsModule();
	CpuModule   cpu = CpuModule();
	RamModule   ram = RamModule();
    NetworkModule   net = NetworkModule();

    gethostname(name, _SC_HOST_NAME_MAX);
	std::cout << "time : " << time.getFormatedTime() << std::endl;
    std::cout << "name : " << name << std::endl;
    std::cout << "host : " << mod.getHostInfo();
    std::cout << "user : " << mod.getUserInfo();
	std::cout << os.getOsInfo() << std::endl;
	net.NetworkUsage();
	std::string value = std::to_string(GetOSVersionComponent(1))+ "." + std::to_string(GetOSVersionComponent(2))+ "." + std::to_string(GetOSVersionComponent(3));
	std::cout << value << std::endl;
	/*uint64_t startCount = rdtsc();
	sleep(1);
	uint64_t endCount = rdtsc();
	std::cout << endCount - startCount;*/
	//while(1)
	//	ram.update();


    return (0);
}
