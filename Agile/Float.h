#pragma once


#include "CAgentField.h"

class Float : public CAgentField {
public:
    Float();

    ~Float();

    Float &operator+=(Float const &);

    Float &operator-=(Float const &);
};



