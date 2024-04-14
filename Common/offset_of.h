#pragma once

#include <cstddef>

#ifdef BROKEN_OFFSETOF_MACRO
#undef offsetof
#define offsetof(type, member)   ((size_t)((char *)&(*(type *)0).member - \
                                           (char *)&(*(type *)0)))
#endif /* BROKEN_OFFSETOF_MACRO */