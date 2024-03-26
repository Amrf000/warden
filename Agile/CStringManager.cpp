// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#include "CStringManager.h"
#include "memory.h"
#include <new>

CStringManager::CStringManager() {
}

CStringManager *CStringManager::getInstance() {
    static CStringManager *dword_D6E380 = nullptr;
    if (!dword_D6E380) {
        CStringManager *v0 = (CStringManager *) sub_B3FE(
                0x28u,
                "/Volumes/F1/usrbuild/xb/build/War3x_B6401/War3/Source/Mac/../../../Engine/Source/Base/RCString.cpp",
                34,
                0);
        if (v0) {
            v0 = new(v0) CStringManager();
        }
        dword_D6E380 = v0;
    }
    return dword_D6E380;
}

