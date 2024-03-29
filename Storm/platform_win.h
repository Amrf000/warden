// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_PLATFORM_WIN_H
#define WARDEN_PLATFORM_WIN_H


#include <Windows.h>

typedef size_t Size;
typedef void *Handle;

FARPROC Carb_SystemFrameworkImport(const char *functionName);

Handle __cdecl NewHandle(Size byteCount);

Handle __cdecl NewHandleClear(Size byteCount);

Size __cdecl GetHandleSize(Handle h);

void __cdecl DisposeHandle(Handle h);

#endif //WARDEN_PLATFORM_WIN_H
