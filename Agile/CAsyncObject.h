// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/28.
//

#ifndef WARDEN_CASYNCOBJECT_H
#define WARDEN_CASYNCOBJECT_H

#include "common.h"
#include <cstdint>

class CAsyncQueue;

class SFile;

class CAsyncObject {
public:
    // Member variables
    SFile *file;
    void *buffer;
    uint32_t size;
    void *userArg;

    void (*userPostloadCallback)(void *);

    void (*userFailedCallback)(void *);

    CAsyncQueue *queue;
    void *ptr1C;
    uint8_t priority;
    uint8_t isProcessed;
    uint8_t isRead;
    uint8_t isCurrent;
    uint8_t char24;
    uint8_t char25;
    uint8_t padding[2];
    TSLink<CAsyncObject> link;
};


#endif //WARDEN_CASYNCOBJECT_H
