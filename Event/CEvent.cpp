// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.


#include "CEvent.h"
#include "../Storm/memory.h"

CEvent::CEvent(unsigned int eventId, void *eventData) : eventId(eventId), eventData(eventData) {}

CEvent::CEvent(const CEvent &other) : TRefCnt(other), eventId(other.eventId), eventData(other.eventData) {}

CEvent &CEvent::operator=(const CEvent &other) {
    if (this != &other) {
        TRefCnt::operator=(other);
        eventId = other.eventId;
        eventData = other.eventData;
    }
    return *this;
}

CEvent::~CEvent() {

}

void CEvent::HeadFree() {
    if (this) {
        DeallocateMemory(this);
    }
}
