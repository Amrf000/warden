#include "Atomic.h"
#include <windows.h>


ATOMIC32 SInterlockedDecrement(ATOMIC32 *ptr) {
    return InterlockedDecrement(ptr);
}

ATOMIC32 SInterlockedIncrement(ATOMIC32 *ptr) {
    return InterlockedIncrement(ptr);
}
