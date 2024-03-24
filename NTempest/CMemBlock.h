// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/10.
//

#ifndef ENGINE_CMEMBLOCK_H
#define ENGINE_CMEMBLOCK_H

#include "Storm.h"
#include "CEntity.h"
#include "CDynParms.h"

namespace NTempest {
    class CMemBlock : public CEntity {
    public:
        CMemBlock(CDynParms const &a2, int a3, const char *a4, int a5) {
            this->a2 = 0;
            this->CMemBlock_Malloc(a2, a3);
        }

        void CMemBlock_Malloc(int a2, int a3) {
            void *v3;
            size_t v5;
            this->CMemBlock_Clear();
            v5 = a2 + a3;
            if (a2 + a3)
                v3 = HeapCalloc(
                        v5,
                        "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Tempest/cmemblock.cpp",
                        372,
                        8);
            else
                v3 = (void *) -1;
            this->a2 = v3;
            this->a3 = v5;
            this->a5 = a2;
            this->a4 = a3 + v3;
        }

        void CMemBlock_Clear() {
            if (this->a2) {
                if (this->a2 != (void *) -1)
                    HeapFree(this->a2);
                this->a5 = 0;
                this->a3 = 0;
                this->a4 = 0;
                this->a2 = 0;
            }
        }

        void *sub_2D4DE8(NTempest::CMemBlock *that) {
            void *result;
            int v3;
            this->CMemBlock_Malloc(that->a5, that->a3 - that->a5);
            result = (void *) this->a2;
            if (result) {
                v3 = this->a3;
                if ((unsigned int) v3 >= that->a3)
                    v3 = that->a3;
                result = (void *) that->a2;
                if (v3 > 0)
                    result = memmove((void *) this->a2, result, v3);
            }
            return result;
        }

        NTempest::CMemBlock *CMemBlock_Clone(NTempest::CMemBlock *that) {
            int v2;

            CMemBlock_Clear();
            CMemBlock_Malloc(that->a5, that->a3 - that->a5);
            if (this->a2) {
                v2 = this->a3;
                if ((unsigned int) v2 >= that->a3)
                    v2 = that->a3;
                if (v2 > 0)
                    memmove((void *) this->a2, (const void *) that->a2, v2);
            }
            return this;
        }

        int sub_2D4B4C(int a2, int a3) {
            int v3;
            void *v4;
            void *v5;
            size_t v7;

            if (this->a5 != a2) {
                v3 = this->a3 - this->a5;
                v7 = v3 + a2;
                if (v3 + a2) {
                    v4 = this->a2;
                    if (v4 == (void *) -1)
                        v5 = HeapCalloc(
                                v7,
                                "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Tempest/cmemblock.cpp",
                                372,
                                8);
                    else
                        v5 = (void *) HeapRealloc(
                                v4,
                                v7,
                                "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Tempest/cmemblock.cpp",
                                372,
                                8);
                    this->a2 = v5;
                } else {
                    HeapFree(this->a2);
                    this->a2 = (void *) -1;
                }
                this->a4 = this->a2 + v3;
                this->a3 = v7;
                this->a5 = a2;
            }
            if (!a3)
                sub_2D4AA2(this->a4, 0, this->a5);
            return 1;
        }

        virtual ~CMemBlock() {
            this->CMemBlock_Clear();
        }

        virtual void Release() {
            this->~CMemBlock();
            DeallocateMemoryEx((void *) this);
        }

    public:
        void *a2;
        int a3;
        int a4;
        int a5;
        int filed_16;
        int filed_20;
        int filed_24;
        int filed_28;
    };
}


#endif //ENGINE_CMEMBLOCK_H
