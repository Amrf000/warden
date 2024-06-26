#pragma once

#include <cstdint>
#include "M2Model.h"
#include "M2Types.h"
#include "Common/TSGrowableArray.h"
#include <NTempest/C44Matrix.h>

using namespace NTempest;


class CM2Cache;

class CM2Light;

class CM2Lighting;

class CM2Model;

class CM2Scene {
public:
    // Static variables
    static uint32_t s_optFlags;

    // Static functions
    static void AnimateThread(void *arg);

    static void ComputeElementShaders(M2Element *element);

    static int32_t SortOpaque(uint32_t a, uint32_t b, const void *userArg);

    static int32_t SortOpaqueGeoBatches(M2Element *elementA, M2Element *elementB);

    static int32_t SortOpaqueParticles(M2Element *elementA, M2Element *elementB);

    static int32_t SortOpaqueRibbons(M2Element *elementA, M2Element *elementB);

    static int32_t SortTransparent(uint32_t a, uint32_t b, const void *userArg);

    // Member variables
    CM2Cache *m_cache;
    CM2Model *m_modelList = nullptr;
    uint32_t m_time = 0;
    uint32_t uint10;
    uint32_t uint14 = 0;
    uint32_t m_flags = 0;
    CM2Light *m_lightList = nullptr;
    CM2Model *m_animateList = nullptr;
    CM2Model *m_drawList = nullptr;
    TSGrowableArray<M2Element> m_elements;
    TSGrowableArray<uint32_t> array44;
    TSGrowableArray<uint32_t> array54[3];
    C44Matrix m_view;
    C44Matrix m_viewInv;
    uint32_t uint104 = 0;

    // Member functions
    CM2Scene(CM2Cache *cache)
            : m_cache(cache) {};

    void AdvanceTime(uint32_t a2);

    void Animate(const C3Vector &cameraPos);

    CM2Model *CreateModel(const char *file, uint32_t a3);

    int32_t Draw(M2PASS pass);

    void SelectLights(CM2Lighting *lighting);
};

