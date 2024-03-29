#pragma once

#include "TSLink.h"
#include <cstddef>
#include <cstdint>

template<typename T>
class TSGetExplicitLink {
    TSLink<T> *Link(const void *nodeptr, ptrdiff_t linkoffset) {
        return reinterpret_cast<TSLink<T> *>((reinterpret_cast<uintptr_t>(nodeptr) + linkoffset));
    }
};


