#pragma once


#include <cstddef>
#include <cstdint>
#include "Agile/CHandleObject.h"

typedef void *HANDLE;

#define DECLARE_HANDLE(name) \
    struct name##__;         \
    typedef struct name##__* name

DECLARE_HANDLE(HOBJECT);

HOBJECT HandleCreate(CHandleObject *ptr);

void HandleClose(HOBJECT handle);

CHandleObject *HandleDereference(HOBJECT handle);

HOBJECT HandleDuplicate(HOBJECT handle);


