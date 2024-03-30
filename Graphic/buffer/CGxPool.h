#pragma once

#include "gx/buffer/CGxBuf.h"
#include "gx/buffer/Types.h"
#include <cstdint>
#include <storm/List.h>

class CGxPool : public TSLinkedNode<CGxPool> {
    public:
        // Member variables
        EGxPoolTarget m_target;
        EGxPoolUsage m_usage;
        int32_t m_size;
        void* m_apiSpecific;
        void* m_mem;
        int32_t unk1C; // TODO
        TSList<CGxBuf, TSGetLink<CGxBuf>> m_bufList;
        EGxPoolHintBits m_hint;
        const char* m_name;

        // Member functions
        CGxPool() = default;
        CGxPool(EGxPoolTarget target, EGxPoolUsage usage, uint32_t size, EGxPoolHintBits hint, const char* name)
            : m_target(target)
            , m_usage(usage)
            , m_size(size)
            , m_apiSpecific(nullptr)
            , unk1C(0)
            , m_hint(hint)
            , m_name(name)
            {};
        void Discard();
        void Invalidate();
};


