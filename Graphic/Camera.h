#pragma once

#include <cstdint>


typedef HDATAMGR HCAMERA;

class CRect;

class C2Vector;

HCAMERA CameraCreate(void);

void CameraSetupScreenProjection(const CRect &, const C2Vector &, float, int32_t);

void CameraSetupWorldProjection(HCAMERA camera, const CRect &projectionRect, uint32_t flags);


