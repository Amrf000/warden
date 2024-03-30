#pragma once

#include "CGxBatch.h"
#include "Types.h"
#include <cstdint>

class C3Vector;

class CImVector;

void GxDraw(CGxBatch *batch, int32_t indexed);

void GxDrawLockedElements(EGxPrim primType, uint32_t indexCount, const uint16_t *indices);

void GxSceneClear(uint32_t, CImVector);

void GxScenePresent(uint32_t a2);

void GxSub682A00();

void GxuFlushDrawList(EGxuDrawListCategory, const C3Vector &);


