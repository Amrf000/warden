// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#ifndef ENGINE_CTARGETPRTG_H
#define ENGINE_CTARGETPRTG_H

#include <cstdint>
#include "CPresenceTagged.h"

namespace NTempest {
    class CTargetPrTg {
    public:
        CTargetPrTg(CPresenceTagged *a2, int a3) {
            this->a3 = 0;
            this->SetTarget(a2);
            this->a3 = a3;
        }

        int SetTarget(CPresenceTagged *a2) {
            int result;
            if (a2) {
                this->a1 = a2->a6;
                result = a2->a7;
                this->a2 = result;
            } else {
                this->a2 = -1;
                this->a1 = -1;
            }
            return result;
        }

    public:
        int a1;
        int a2;
        int a3;
    };
}


#endif //ENGINE_CTARGETPRTG_H
