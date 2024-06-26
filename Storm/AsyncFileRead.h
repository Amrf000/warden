#pragma once

#include "CAsyncQueue.h"
#include "CAsyncThread.h"
#include "Storm/thread/SEvent.h"
#include "Storm/thread/SCritSect.h"
#include <Common/Prop.h>
#include "Common/TSList.h"
#include "Common/TSExplicitList.h"
#include <Storm/Thread.h>

#define NUM_ASYNC_QUEUES 3

class CAsyncObject;

class AsyncFileRead {
public:
    // Static variables
    static uint32_t s_threadSleep;
    static uint32_t s_handlerTimeout;
    static CAsyncObject *s_asyncWaitObject;
    static void *s_progressCallback;
    static void *s_progressParam;
    static int32_t s_progressCount;
    static void *s_ingameProgressCallback;
    static void *s_ingameStartCallback;
    static HPROPCONTEXT s_propContext;
    static SEvent s_shutdownEvent;
    static const char *s_asyncQueueNames[];
    static CAsyncQueue *s_asyncQueues[];
    static SCritSect s_queueLock;
    static SCritSect s_userQueueLock;
    static TSList<CAsyncQueue, TSGetLink<CAsyncQueue>> s_asyncQueueList;
    static TSList<CAsyncThread, TSGetLink<CAsyncThread>> s_asyncThreadList;
    static STORM_EXPLICIT_LIST(CAsyncObject, link) s_asyncFileReadPostList;
    static STORM_EXPLICIT_LIST(CAsyncObject, link) s_asyncFileReadFreeList;
    static int32_t s_waiting;
};

CAsyncQueue *AsyncFileReadCreateQueue();

void AsyncFileReadCreateThread(CAsyncQueue *queue, const char *queueName);

void AsyncFileReadLinkObject(CAsyncObject *object, int32_t a2);

int32_t AsyncFileReadPollHandler(const void *a1, void *a2);

uint32_t AsyncFileReadThread(void *thread);

void AsyncFileReadWait(CAsyncObject *object);


