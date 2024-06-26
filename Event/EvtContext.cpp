#include "event/EvtContext.h"
#include "Storm/Time.h"
#include "Common/Prop.h"
#include "Common/offset_of.h"

EvtContext::EvtContext(uint32_t flags, uint32_t idleTime, uint32_t schedWeight, void *callContext,
                       int32_t startWatchdog) :
        TSingletonInstanceId<EvtContext, STRUCT_OFFSET(TInstanceId<EvtContext>, m_id)>(),
        m_critsect(),
        m_schedNextWakeTime(),
        m_queueHandlerList(),
        m_queueMessageList(),
        m_queueSyncKeyDownList()
// TODO
// m_timerIdTable()
{
    this->m_currTime = 0;
    this->m_schedState = SCHEDSTATE_ACTIVE;
    this->m_schedLastIdle = OsGetAsyncTimeMs();
    this->m_schedFlags = flags;
    this->m_schedIdleTime = idleTime;
    this->m_schedInitialIdleTime = idleTime;
    this->m_schedWeight = schedWeight;
    this->m_schedSmoothWeight = schedWeight;
    this->m_schedRebalance = 0;
    this->m_queueSyncButtonState = 0;
    this->m_propContext = PropCreateContext();
    this->m_callContext = callContext;
    this->m_startWatchdog = startWatchdog;
}

EvtContextQueue::EvtContextQueue() : TSPriorityQueue<EvtContext>(STRUCT_OFFSET(EvtContext, m_schedNextWakeTime)) {
}
