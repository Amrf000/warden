//
// Created by liuyawu on 2019/5/9.
//

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
            if ( a2 )
            {
                this->a1 = a2->a6;
                result = a2->a7;
                this->a2 = result;
            }
            else
            {
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
