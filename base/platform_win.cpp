// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//
#include <iostream>
#include "platform_win.h"

FARPROC Carb_SystemFrameworkImport(const char *functionName) {
    HMODULE hModule = nullptr;
    //SetDllDirectory(NULL);
    // if (0 == strncmp(functionName, "_msize", 6)) {
    hModule = LoadLibraryA("msvcrt.dll");//msvcrt.dll
//    } else {
//        hModule = LoadLibraryA("System.dll");
//    }

    if (hModule == NULL) {
        auto err = GetLastError();
        std::cerr << "Get Last Error : " << err << std::endl;
        return NULL;
    }

    FARPROC functionPtr = GetProcAddress(hModule, functionName);

    if (functionPtr == NULL) {
        // 处理获取函数指针失败的情况
        FreeLibrary(hModule);
        return NULL;
    }

    // 成功加载 DLL 并获取函数指针
    return functionPtr;
}


Handle __cdecl NewHandle(Size byteCount) {
    return static_cast<Handle>(malloc(byteCount));
}

Handle __cdecl NewHandleClear(Size byteCount) {
    Handle h = malloc(byteCount);
    if (h != nullptr) {
        memset(h, 0, byteCount);
    }
    return h;
}

Size __cdecl GetHandleSize(Handle h) {
    return _msize(h);
}


void __cdecl DisposeHandle(Handle h) {
    free(h);
}
