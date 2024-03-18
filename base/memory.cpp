// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#include "memory.h"


// Global variables
static int dword_F33CE4 = 0; // Represents memory usage
MallocFunction dword_F33CEC = nullptr;
FreeFunction dword_F33CF4 = nullptr;
ReallocFunction dword_F33CF8 = nullptr;
CallocFunction dword_F33CF0 = nullptr;
MallocSizeFunction dword_F33CE8 = nullptr;


int16_t InitializeSystem() {
    // int16_t response[3];
//    int16_t gestaltResult = Gestalt(0x73797376u, response);
//
//    if (gestaltResult == 0 && response[0] > 4095) {
    dword_F33CEC = (MallocFunction) Carb_SystemFrameworkImport("malloc");
    dword_F33CF4 = (FreeFunction) Carb_SystemFrameworkImport("free");
    dword_F33CF8 = (ReallocFunction) Carb_SystemFrameworkImport("realloc");
    dword_F33CF0 = (CallocFunction) Carb_SystemFrameworkImport("calloc");
    dword_F33CE8 = (MallocSizeFunction) Carb_SystemFrameworkImport("_msize");//malloc_size
    // }

    //return gestaltResult;
    return 0;
}

// Function to deallocate memory
void DeallocateMemory(void *memoryBlock) {
    int blockSize = dword_F33CE8(memoryBlock);
    dword_F33CE4 -= blockSize;
    dword_F33CF4(memoryBlock);
}

// Function to allocate memory
void *AllocateMemory(int size) {
    void *block = dword_F33CF0(size, 1);
    dword_F33CE4 += dword_F33CE8(block);
    return block;
}

// Function to allocate zero-initialized memory
void *AllocateZeroInitializedMemory(size_t size) {
    if (!dword_F33CF0 || !dword_F33CEC)
        InitializeSystem();

    void *allocatedMemory = dword_F33CF0(size, 1);
    dword_F33CE4 += dword_F33CE8(allocatedMemory);
    return reinterpret_cast<void *>(allocatedMemory);
}

// Function to allocate memory and optionally initialize with a specific value
void *AllocateMemoryWithInitialization(size_t size, int16_t options) {
    if (!dword_F33CF0 || !dword_F33CEC)
        InitializeSystem();

    void *allocatedMemory = nullptr;
    if (options & 0x100) {
        allocatedMemory = reinterpret_cast<void *>(dword_F33CF0(size, 1));
    } else if (options & 0x4000) {
        allocatedMemory = reinterpret_cast<void *>(dword_F33CEC(size));
        memset(allocatedMemory, 238, size);
    } else {
        allocatedMemory = reinterpret_cast<void *>(dword_F33CEC(size));
    }

    dword_F33CE4 += dword_F33CE8(allocatedMemory);
    return allocatedMemory;
}

// Function to create a new handle
Handle CreateHandle(Size byteCount) {
    Handle newHandle = NewHandle(byteCount);
    dword_F33CE4 += byteCount;
    return newHandle;
}

// Function to deallocate a handle
void DeallocateHandle(Handle handle) {
    dword_F33CE4 -= GetHandleSize(handle);
    DisposeHandle(handle);
}

// Function to get current memory usage
int GetCurrentMemoryUsage() {
    return dword_F33CE4;
}

