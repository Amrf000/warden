// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CMEMBLOCKT_H
#define ENGINE_CMEMBLOCKT_H

#include "CMemBlock.h"
#include "CDynParms.h"

namespace NTempest {

    template<typename T>
    class CMemBlockT : public CMemBlock {
    public:
        CMemBlockT(CDynParms const &a2, int a3, const char *a4, int a5) : CMemBlock(a2, a3, a4, a5) {}

        virtual ~CMemBlockT() {}

        virtual void Release() {
            this->~CMemBlockT();
            DeallocateMemoryEx(this);
        }
    };
}


#endif //ENGINE_CMEMBLOCKT_H
