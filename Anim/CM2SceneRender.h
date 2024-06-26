#pragma once

#include "Graphic/Types.h"
#include "CM2Scene.h"
#include "M2Types.h"
#include <cstdint>

class CM2Cache;

class CM2Lighting;

class CM2Model;

class CM2Shared;

struct M2Batch;
struct M2Data;
struct M2Element;
struct M2Material;
struct M2SkinSection;

class CM2SceneRender {
public:
    // Static variables
    static C44Matrix s_identity;
    static int32_t s_fogModeList[M2BLEND_COUNT];
    static EGxBlend s_gxBlend[M2PASS_COUNT][M2BLEND_COUNT];
    static int32_t s_shadedList[M2BLEND_COUNT];

    // Member variables
    C44Matrix matrix0;
    CM2Scene *m_scene;
    CM2Cache *m_cache;
    M2Data *m_data = nullptr;
    M2PASS m_curPass;
    M2Element *m_curElement = nullptr;
    M2Element *m_prevElement = nullptr;
    uint32_t m_curType = -1u;
    uint32_t m_prevType = -1u;
    CM2Model *m_curModel = nullptr;
    CM2Model *m_prevModel = nullptr;
    CM2Shared *m_curShared = nullptr;
    CM2Shared *m_prevShared = nullptr;
    CM2Lighting *m_curLighting = nullptr;
    CM2Lighting *m_prevLighting = nullptr;
    uint32_t m_curShaded = 0;
    uint32_t m_prevShaded = 0;
    uint32_t m_curFogMode = -1u;
    uint32_t m_prevFogMode = -1u;
    M2Batch *m_curBatch = nullptr;
    M2Batch *m_prevBatch = nullptr;
    M2SkinSection *m_curSkinSection = nullptr;
    M2SkinSection *m_prevSkinSection = nullptr;
    M2Material *m_curMaterial = nullptr;
    M2Material *m_prevMaterial = nullptr;

    // Member functions
    CM2SceneRender(CM2Scene *scene)
            : m_scene(scene), m_cache(scene->m_cache) {};

    void Draw(M2PASS pass, M2Element *elements, uint32_t *a4, uint32_t a5);

    void DrawBatch();

    void DrawBatchDoodad(M2Element *elements, uint32_t *a3);

    void DrawBatchProj();

    void DrawCallback();

    int32_t DrawParticle(uint32_t a2, M2Element *elements, uint32_t *a4, uint32_t a5);

    void DrawRibbon();

    void SetBatchVertices(int32_t a2);

    void SetupBatchVertices();

    void SetupLighting();

    void SetupMaterial();

    void SetupTextures();
};


