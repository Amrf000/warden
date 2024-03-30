#pragma once

#include "Storm.h"

namespace NTempest {
    class CEntity {
    public:
        virtual ~CEntity() {
        }

        virtual void Release() {
            this->~CEntity();
            DeallocateMemoryEx(this);
        }
    };
}



