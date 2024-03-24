// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CPRESENCEREG_H
#define ENGINE_CPRESENCEREG_H

#include <ntdef.h>
#include "CDynTable.h"
#include "CPrRgEntry.h"

namespace NTempest {
    class CPresenceReg {
    public:
        ~CPresenceReg() {
        }

        CPresenceReg(int a2) {
            CDynTable<CPrRgEntry>::CDynTable(a1, a2, 0, 0, 0);
            CDynTable<CPrRgEntry>::CDynTable(a1 + 8, a2, 0, 0, 0);
            a1[16] = -1;
            a1[17] = -1;
            a1[18] = 0;
            a1[19] = 0;
            a1[20] = 0;
            a1[21] = 0;
            a1[22] = 0;
        }

        bool IsAssociated(unsigned int a2) {
            CPresenceReg *v2;
            unsigned int v3;

            v2 = this;
            v3 = a2;
            if ((a2 & 0x80000000) != 0) {
                v3 = a2 & 0x7FFFFFFF;
                v2 = (CPresenceReg *) ((char *) this + 32);
            }
            return v3 < *((uint32_t *) v2 + 7) && *(uint32_t *) (*((uint32_t *) v2 + 3) + 8 * v3) == -2;
        }

        int Presence(unsigned int a2) {
            int v2;

            if ((a2 & 0x80000000) == 0)
                v2 = *((uint32_t *) this + 3);
            else
                v2 = *((uint32_t *) this + 11);
            return *(uint32_t *) (v2 + 8 * a2 + 4);
        }

        unsigned int PredictTag(int a2) {
            int v2;
            unsigned int result;

            if (a2) {
                v2 = *((uint32_t *) this + 17);
                if (v2 == -1)
                    v2 = *((uint32_t *) this + 15);
                result = v2 | 0x80000000;
            } else {
                result = *((uint32_t *) this + 16);
                if (result == -1)
                    result = *((uint32_t *) this + 7);
            }
            return result;
        }

    public:
        CDynTable<CPrRgEntry> a1;
        CDynTable<CPrRgEntry> a2;
    };
}


#endif //ENGINE_CPRESENCEREG_H
