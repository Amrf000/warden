// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#pragma once

#include "CEvent.h"
#include "Types.h"

class CMouseEvent : public CEvent, public EVENT_DATA_MOUSE {
public:
    // Member functions
    CMouseEvent &operator=(const EVENT_DATA_MOUSE &data);
};
