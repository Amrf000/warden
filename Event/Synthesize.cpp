#include "event/Synthesize.h"
#include "event/EvtContext.h"
#include "event/Queue.h"
#include "Storm/Time.h"

void SynthesizeDestroy(EvtContext *context) {
    // TODO
    exit(0);
}

void SynthesizeIdle(EvtContext *context, uint32_t currTime, float elapsedSec) {
    bool closed;

    context->m_critsect.Enter();
    closed = context->m_schedState == EvtContext::SCHEDSTATE_CLOSED;
    context->m_critsect.Leave();

    if (closed) {
        return;
    }

    uint32_t schedFlags = context->m_schedFlags;

    if (schedFlags & 0x2) {
        context->m_schedFlags = schedFlags | 0x4;
    }

    EVENT_DATA_IDLE data;
    data.elapsedSec = elapsedSec;
    data.time = currTime;

    IEvtQueueDispatch(context, EVENT_ID_IDLE, &data);
}

int32_t SynthesizeInitialize(EvtContext *context) {
    uint32_t schedFlags = context->m_schedFlags;

    if (schedFlags & 0x1) {
        return 0;
    }

    context->m_schedFlags = schedFlags | 0x1;
    context->m_schedLastIdle = OsGetAsyncTimeMs();

    IEvtQueueDispatch(context, EVENT_ID_INITIALIZE, nullptr);

    return 1;
}

void SynthesizePaint(EvtContext *context) {
    bool closed;

    context->m_critsect.Enter();
    closed = context->m_schedState == EvtContext::SCHEDSTATE_CLOSED;
    context->m_critsect.Leave();

    if (closed) {
        return;
    }

    uint32_t schedFlags = context->m_schedFlags;

    if (schedFlags & 0x4) {
        context->m_schedFlags = schedFlags & ~0x4;
        IEvtQueueDispatch(context, EVENT_ID_PAINT, nullptr);
    }
}

void SynthesizePoll(EvtContext *context) {
    bool closed;

    context->m_critsect.Enter();
    closed = context->m_schedState == EvtContext::SCHEDSTATE_CLOSED;
    context->m_critsect.Leave();

    if (closed) {
        return;
    }

    IEvtQueueDispatch(context, EVENT_ID_POLL, nullptr);
}
