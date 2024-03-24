//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CLINKEDNODECACHE_H
#define ENGINE_CLINKEDNODECACHE_H

namespace NTempest {
    template <typename T>
    class CLinkedNodeCache {
    public:
        int  ~CLinkedNodeCache(int a1)
        {
            TInstanceCache<CPresenceTagged>::Clear(a1);
            return sub_B808(a1);
        }

        int  CLinkedNodeCache(int a1, int a2)
        {
            int result;

            result = TInstanceCache<CPresenceTagged>::TInstanceCache(a1, a2);
            *(uint32_t *)(a1 + 28) = 0;
            return result;
        }

        int  Dispose(int a1, int a2)
        {
            int v2;
            int v3;
            int result;

            v2 = *(uint32_t *)(a2 + 4);
            v3 = *(uint32_t *)(a2 + 8);
            if ( v2 )
                *(uint32_t *)(v2 + 8) = v3;
            if ( v3 )
                *(uint32_t *)(v3 + 4) = v2;
            *(uint32_t *)(a2 + 4) = 0;
            *(uint32_t *)(a2 + 8) = 0;
            result = *(uint32_t *)(a1 + 20);
            *(uint32_t *)(a2 - 4) = result;
            *(uint32_t *)(a1 + 20) = a2 - 4;
            --*(uint32_t *)(a1 + 24);
            return result;
        }
    };
}

#endif //ENGINE_CLINKEDNODECACHE_H
