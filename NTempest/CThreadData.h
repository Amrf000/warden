// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CTHREADDATA_H
#define ENGINE_CTHREADDATA_H

#include <cstdint>
#include "Storm.h"
#include "CPresenceReg.h"
#include "CLinkedNodeCache.h"
#include "CPresenceTagged.h"
#include "CPresence.h"
#include "CPresenceSys.h"
#include "CPresenceSysTagged.h"


namespace NTempest {
    class CThreadData;

    CThreadData *unk_D6E440 = nullptr;
    CThreadData *dword_D6E460 = nullptr;

    class CThreadData {
    public:
        CThreadData() {
            int *result;
            int v2[8];

            v2[0] = 0;
            v2[1] = 2048;
//            CPresenceReg::CPresenceReg(this, v2);
//            CLinkedNodeCache<CPresence>::CLinkedNodeCache((char *) this + 92, 64);
//            CLinkedNodeCache<CPresenceSys>::CLinkedNodeCache((char *) this + 124, 64);
//            CLinkedNodeCache<CPresenceTagged>::CLinkedNodeCache((char *) this + 156, 64);
//            CLinkedNodeCache<CPresenceSysTagged>::CLinkedNodeCache((char *) this + 188, 64);
            dword_D6E460 = this;
        }

        ~CThreadData() {
        }

        CThreadData *SetT_() {
            TRefCnt *v1;
            v1 = (TRefCnt *) unk_D6E440;
            if (unk_D6E440) {
                unk_D6E440->~CThreadData();
                DeallocateMemoryEx(v1);
            }
            unk_D6E440 = this;
            return this;
        }


        int Checksum() {
            unsigned int i;
            uint32_t *v2;
            int v3;
            int v5[3];

            v5[0] = 0;
            for (i = 0; i < *((uint32_t *) this + 7); ++i) {
                v2 = (uint32_t *) (*((uint32_t *) this + 3) + 8 * i);
                if (*v2 == -2) {
                    v3 = v2[1];
                    if (v3)
                        (*(void (**)(int, int *)) (*(uint32_t *) v3 + 64))(v3, v5);
                }
            }
            return v5[0];
        }

    public:
        CPresenceReg a1;
        CLinkedNodeCache<CPresence> a2;
        CLinkedNodeCache<CPresenceSys> a3;
        CLinkedNodeCache<CPresenceTagged> a4;
        CLinkedNodeCache<CPresenceSysTagged> a5;

    };
}

#endif //ENGINE_CTHREADDATA_H
