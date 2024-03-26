// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.
#ifndef ENGINE_CDYNTABLE_H
#define ENGINE_CDYNTABLE_H

#include "CMemBlockT.h"
#include "CDynParms.h"

namespace NTempest {
    template<typename T>
    class CDynTable : public CMemBlockT<T> {
    public:
        CDynTable(CDynParms const &a2, int a3, const char *a4, int a5) : CMemBlockT<T>(a2, a, a4, a5) {}

        virtual ~CDynTable() {}

        virtual void Release() {
            this->~CMemBlockT();
            DeallocateMemoryEx(this);
        }
    };
}

#endif //ENGINE_CDYNTABLE_H
