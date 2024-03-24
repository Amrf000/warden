// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/10.
//

#ifndef ENGINE_CENTITY_H
#define ENGINE_CENTITY_H

#include <cstdint>


namespace NTempest {
    class CEntity {
    public:
        virtual ~CEntity() {
        }

        virtual int Release() {
            this->~CEntity();
            return DeallocateMemoryEx(this);
        }
    };
}


#endif //ENGINE_CENTITY_H
