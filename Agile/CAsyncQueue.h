#pragma once


#include "common.h"
#include "CAsyncObject.h"

class CAsyncQueue : public TSLinkedNode<CAsyncQueue> {
public:
    // Member variables
    TSGetExplicitLink<CAsyncObject> readList;
    TSGetExplicitLink<CAsyncObject> list14;
    int32_t int20;
};



