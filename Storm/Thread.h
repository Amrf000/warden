#ifndef STORM_THREAD_HPP
#define STORM_THREAD_HPP

#include <cstdint>
#include "Storm/thread/SThread.h"

void *
SCreateThread(uint32_t (*threadProc)(void *), void *threadParam, void *a3, SThread *syncObject, const char *threadName);

uintptr_t SGetCurrentThreadId();

#endif
