#pragma once

#include "event/Types.h"
#include <cstdint>

class EvtContext;

HEVENTCONTEXT AttachContextToThread(EvtContext* context);

void DetachContextFromThread(uint32_t a1, EvtContext* a2);

EvtContext* GetNextContext(uint32_t hThread);

void PutContext(uint32_t nextWakeTime, uint32_t newSmoothWeight, EvtContext* context, uint32_t hThread);


