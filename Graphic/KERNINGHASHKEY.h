#pragma once


#include <cstdint>

class KERNINGHASHKEY {
public:
    // Member variables
    uint32_t code;

    // Member functions
    KERNINGHASHKEY &operator=(const KERNINGHASHKEY &);

    bool operator==(const KERNINGHASHKEY &);
};
