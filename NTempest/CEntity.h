#pragma once


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



