#pragma once

#if !defined(DECLARE_HANDLE)
#define DECLARE_HANDLE(name) \
    struct name##__;         \
    typedef struct name##__* name
#endif


