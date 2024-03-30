#pragma once

#include "event/Types.h"
#include "Common/instance/TExtraInstanceRecyclable.h"

class EvtMessage : public TExtraInstanceRecyclable<EvtMessage> {
public:
    // Member variables
    TSLink<EvtMessage> link;
    EVENTID id;
    char data[4];
};


