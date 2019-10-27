//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#include "../incs/UserModule.hpp"
#include "../incs/OsMonitor.hpp"
#include "../incs/SdlClass.hpp"

int         main() {
    SdlClass win;

    while (win.isRunning())
        win.update();
    return (0);
}
