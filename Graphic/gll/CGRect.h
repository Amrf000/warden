#pragma once
struct CGRect_ {
    float x;
    float y;
    float width;
    float height;
};

struct CGRect {
    struct CGRect_ origin;
    struct CGRect_ size;
};
