#include "CatModule.hpp"

std::string cat = "\\    /\\\n )  ( ')\n(  /  )\n \\(__)|";
std::string cat2 = " /   /\\\n )  ( `)\n(  /  )\n \\(__)|";

CatModule::CatModule() { return ; }

CatModule::~CatModule() {return ;}
CatModule::CatModule(CatModule const &) {return ;}
CatModule &CatModule::operator=(CatModule const &) {
    return *this;
}

std::string CatModule::update() {
	if (time(NULL) % 2 == 0)
		return cat;
	else
		return cat2;
}
