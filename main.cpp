#include <iostream>
#include "Event/Event.h"
#include "Storm/StormInit.h"
#include "Game/Client.h"

void WardenMain() {
    StormInitialize();

    // TODO
    // - error log setup
    // - misc other setup

    if (InitializeGlobal()) {
        EventDoMessageLoop();

        // TODO
        // sub_406B70();
    }
    // TODO
    // - misc cleanup
}

int main() {
    WardenMain();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
