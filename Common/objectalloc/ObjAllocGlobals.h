#pragma once

#include "CObjectHeapList.h"
#include "Storm/thread/SCritSect.h"
#include "Common/TSGrowableArray.h"
#include <Storm/Thread.h>

class OBJALLOCGLOBALS {
public:
    // Static variables
    static OBJALLOCGLOBALS s_globals;
    static SCritSect s_globalsLock;

    // Member variables
    TSGrowableArray <CObjectHeapList> objects;
};

OBJALLOCGLOBALS *GetObjAllocGlobals();

void ReleaseObjAllocGlobals();


