#pragma once


class KERNNODE : public TSHashObject<KERNNODE, KERNINGHASHKEY> {
public:
    // Member variables
    uint32_t flags = 0x0;
    float proporportionalSpacing = 0.0f;
    float fixedWidthSpacing = 0.0f;
};
