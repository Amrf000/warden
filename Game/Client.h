#pragma once


#include <cstdint>
#include "Event/Event.h"

class CVar;

namespace Client {
    extern CVar *g_accountListVar;
    extern HEVENTCONTEXT g_clientEventContext;
}

int32_t InitializeGlobal();
