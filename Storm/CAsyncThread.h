#pragma once

#include <cstdint>
#include "Storm/thread/SThread.h"


class CAsyncObject;

class CAsyncQueue;

class CAsyncThread : public TSLinkedNode<CAsyncThread> {
public:
    // Member variables
    SThread thread;
    CAsyncQueue *queue;
    CAsyncObject *currentObject;
};


