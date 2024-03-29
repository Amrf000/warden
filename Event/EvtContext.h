// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#pragma once

#include <cstdint>
#include "common.h"
#include "EvtHandler.h"
#include "EvtKeyDown.h"
#include "EvtMessage.h"
#include "EvtTimer.h"
#include "Types.h"
#include "EvtTimerQueue.h"
#include <common/Instance.h>
#include <common/Prop.h>
#include <storm/Queue.h>
#include <storm/Thread.h>

class EvtContext : public TSingletonInstanceId<EvtContext, offsetof(TInstanceId < EvtContext >, m_id)> {
public:
    // Types
    enum SCHEDSTATE {
        SCHEDSTATE_ACTIVE = 0x0,
        SCHEDSTATE_CLOSED = 0x1,
        SCHEDSTATE_DESTROYED = 0x2,
        _UNIQUE_SYMBOL_SCHEDSTATE_96 = 0xFFFFFFFF,
    };

    // Member variables
    SCritSect m_critsect;
    uint32_t m_currTime;
    SCHEDSTATE m_schedState;
    TSTimerPriority <uint32_t> m_schedNextWakeTime;
    uint32_t m_schedLastIdle;
    uint32_t m_schedFlags;
    uint32_t m_schedIdleTime;
    uint32_t m_schedInitialIdleTime;
    uint32_t m_schedWeight;
    uint32_t m_schedSmoothWeight;
    int32_t m_schedRebalance;
    TSExplicitList<EvtHandler, offsetof(EvtHandler, link)> m_queueHandlerList[EVENTIDS];
    TSExplicitList<EvtMessage, offsetof(EvtMessage, link)> m_queueMessageList;
    uint32_t m_queueSyncButtonState;
    TSExplicitList<EvtKeyDown, offsetof(EvtKeyDown, link)> m_queueSyncKeyDownList;
    // TODO
    // EvtIdTable<EvtTimer*> m_timerIdTable;
    EvtTimerQueue m_timerQueue;
    HPROPCONTEXT m_propContext;
    void *m_callContext;
    uint32_t m_startWatchdog;

    // Member functions
    EvtContext(uint32_t flags, uint32_t idleTime, uint32_t schedWeight, void *callContext, int32_t startWatchdog);
};

