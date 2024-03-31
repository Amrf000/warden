#pragma once

#include "CAsyncObject.h"
#include "Common/TSLinkedNode.h"
#include "Common/TSGetExplicitLink.h"

class CAsyncQueue : public TSLinkedNode<CAsyncQueue> {
public:
    // Member variables
    TSGetExplicitLink<CAsyncObject> readList;
    TSGetExplicitLink<CAsyncObject> list14;
    int32_t int20;
};



