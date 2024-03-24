// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/17.
//

#ifndef WARDEN_CEVENT_H
#define WARDEN_CEVENT_H


#include "TRefCnt.h"

class CEvent : public TRefCnt {
public:
    CEvent(unsigned int eventId, void *eventData);

    CEvent(const CEvent &other);

    CEvent &operator=(const CEvent &other);

    virtual ~CEvent();

    virtual void HeadFree();

private:
    unsigned int eventId;
    void *eventData;
};


#endif //WARDEN_CEVENT_H
