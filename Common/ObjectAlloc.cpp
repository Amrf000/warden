#include "ObjectAlloc.h"
#include "objectalloc/ObjAllocGlobals.h"
#include <Storm/Error.h>
#include <Storm/String.h>

int32_t ObjectAlloc(uint32_t heapId, uint32_t* memHandle, void** objectPtr, bool zero) {
    STORM_ASSERT(memHandle);

    *memHandle = 0;

    auto globals = GetObjAllocGlobals();

    STORM_ASSERT(heapId < globals->objects.Count());

    uint32_t index;
    void* object;

    if (globals->objects[heapId].New(&index, &object, zero)) {
        if (objectPtr) {
            *objectPtr = object;
        }

        ReleaseObjAllocGlobals();

        *memHandle = index;

        return 1;
    }

    ReleaseObjAllocGlobals();

    return 0;
}

uint32_t ObjectAllocAddHeap(uint32_t objectSize, uint32_t objsPerBlock, const char* name, bool a4) {
    STORM_ASSERT(objectSize > 0);

    auto globals = GetObjAllocGlobals();

    uint32_t heapId = globals->objects.Count();
    auto heap = globals->objects.New();

    heap->m_objSize = objectSize;
    heap->m_objsPerBlock = objsPerBlock;
    SStrCopy(heap->m_heapName, name, sizeof(heap->m_heapName));
    heap->char84 = a4;

    ReleaseObjAllocGlobals();

    return heapId;
}
