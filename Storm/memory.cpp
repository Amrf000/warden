// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#include "memory.h"
#include "DebugUtils.h"

// Global variables
static int dword_F33CE4 = 0; // Represents memory usage
_MallocFunction dword_F33CEC = nullptr;
_FreeFunction dword_F33CF4 = nullptr;
_ReallocFunction dword_F33CF8 = nullptr;
_CallocFunction dword_F33CF0 = nullptr;
_MallocSizeFunction dword_F33CE8 = nullptr;


int16_t InitializeSystem() {
    // int16_t response[3];
//    int16_t gestaltResult = Gestalt(0x73797376u, response);
//
//    if (gestaltResult == 0 && response[0] > 4095) {
    dword_F33CEC = (_MallocFunction) Carb_SystemFrameworkImport("malloc");
    dword_F33CF4 = (_FreeFunction) Carb_SystemFrameworkImport("free");
    dword_F33CF8 = (_ReallocFunction) Carb_SystemFrameworkImport("realloc");
    dword_F33CF0 = (_CallocFunction) Carb_SystemFrameworkImport("calloc");
    dword_F33CE8 = (_MallocSizeFunction) Carb_SystemFrameworkImport("_msize");//malloc_size
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

void *ReallocMemory(void *old_data, int size) {
    int old_size; // edi


    if (old_data)
        old_size = MallocSizeFunction(old_data);
    else
        old_size = 0;
    void *v3 = ReallocFunction(old_data, size);
    IHeapSize = MallocSizeFunction(v3) + IHeapSize - old_size;
    return v3;
}

void *ReallocMemoryEx(void *old_data, int size, const char *info, int a4, char flag) {
    if (old_data && (flag & 0x10) != 0)
        return 0;
    else
        return ReallocMemory(old_data, size);
}

void *SMemAlloc(size_t size, const char *filename, int linenumber, int flags) {
    __int16 option; // ax
    __int16 v5; // dx
    void *MemoryWithInitialization; // esi

    option = (flags & 0x10000000) != 0 ? 0x400 : 0;
    LOBYTE(v5) = option;
    if ((flags & 8) != 0) {
        HIBYTE(v5) = HIBYTE(option) | 1;
        option = v5;
    }
    MemoryWithInitialization = AllocateMemoryWithInitialization(size, option);
    if (!MemoryWithInitialization) {
        if (*filename)
            DebugWrite(8, filename, linenumber, size);
        else
            DebugWrite(8, "SMemAlloc()", -1, size);
    }
    return MemoryWithInitialization;
}

void DeallocateMemoryEx(void *data) {
    if (data)
        DeallocateMemory(data);
}

