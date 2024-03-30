#pragma once

#include <cstdint>

typedef long ATOMIC32;


ATOMIC32 SInterlockedDecrement(ATOMIC32 *ptr);

ATOMIC32 SInterlockedIncrement(ATOMIC32 *ptr);


