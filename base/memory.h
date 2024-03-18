// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_MEMORY_H
#define WARDEN_MEMORY_H

#include "platform_win.h"
#include <cstdlib> // For malloc, free, realloc
#include <cstring> // For memset
#include <cstdint> // For int16_t

typedef void *(__cdecl *MallocFunction)(size_t);

typedef void (__cdecl *FreeFunction)(void *);

typedef void *(__cdecl *ReallocFunction)(void *, size_t);

typedef void *(__cdecl *CallocFunction)(size_t, size_t);

typedef size_t (__cdecl *MallocSizeFunction)(void *);


extern MallocFunction dword_F33CEC;
extern FreeFunction dword_F33CF4;
extern ReallocFunction dword_F33CF8;
extern CallocFunction dword_F33CF0;
extern MallocSizeFunction dword_F33CE8;


// Function to get system information and import necessary functions
int16_t InitializeSystem();

// Function to deallocate memory
void DeallocateMemory(void *memoryBlock);

// Function to allocate memory
void *AllocateMemory(int size);

// Function to allocate zero-initialized memory
void *AllocateZeroInitializedMemory(size_t size);

// Function to allocate memory and optionally initialize with a specific value
void *AllocateMemoryWithInitialization(size_t size, int16_t options);


// Function to create a new handle
Handle CreateHandle(Size byteCount);

// Function to deallocate a handle
void DeallocateHandle(Handle handle);

// Function to get current memory usage
int GetCurrentMemoryUsage();

#endif //WARDEN_MEMORY_H
