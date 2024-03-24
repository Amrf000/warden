// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#include "DebugUtils.h"

void DebugPrint(const char *fmt, ...) {

}

int DebugWrite(int a1, const char *func_name, int a3, int size) {
    char v8[280];

    sub_1AAA2(v8, 256, "%d bytes", size);
    sub_1D242(a1, (int) func_name, a3, v8);
    return sub_115F6();
}

void OsOutputDebugString(const char *fmt, ...) {

}