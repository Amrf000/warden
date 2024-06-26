#include "CWorld.h"
#include "Graphic/Gx.h"
#include "Anim/Model2.h"
#include "Graphic/shader/CShaderEffect.h"


uint32_t CWorld::s_enables;
uint32_t CWorld::s_enables2;

void CWorld::Initialize() {
    CWorld::s_enables |=
            Enables::Enable_1
            | Enables::Enable_2
            | Enables::Enable_10
            | Enables::Enable_Culling
            | Enables::Enable_Shadow
            | Enables::Enable_100
            | Enables::Enable_200
            | Enables::Enable_800
            | Enables::Enable_4000
            | Enables::Enable_DetailDoodads
            | Enables::Enable_1000000
            | Enables::Enable_Particulates
            | Enables::Enable_LowDetail;

    // TODO

    if (GxCaps().m_shaderTargets[GxSh_Pixel] > GxShPS_none) {
        CWorld::s_enables |= Enables::Enable_PixelShader;
    }

    if (GxCaps().m_shaderTargets[GxSh_Vertex] > GxShVS_none) {
        CWorld::s_enables2 |= Enables2::Enable_VertexShader;
    }

    // TODO

    uint32_t m2Flags = M2GetCacheFlags();
    CShaderEffect::InitShaderSystem(
            (m2Flags & 0x8) != 0,
            (CWorld::s_enables2 & Enables2::Enable_HwPcf) != 0
    );

    // TODO
}
