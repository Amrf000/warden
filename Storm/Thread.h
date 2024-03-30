#ifndef STORM_THREAD_HPP
#define STORM_THREAD_HPP

#include "storm/thread/CCritSect.h"
#include "storm/thread/CSRWLock.h"
#include "storm/thread/SCritSect.h"
#include "storm/thread/SEvent.h"
#include "storm/thread/SSemaphore.h"
#include "storm/thread/SSyncObject.h"
#include "storm/thread/SThread.h"
#include <cstdint>

void *
SCreateThread(uint32_t (*threadProc)(void *), void *threadParam, void *a3, SThread *syncObject, const char *threadName);

uintptr_t SGetCurrentThreadId();

#endif
