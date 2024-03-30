


#pragma once

namespace NTempest {
    class CiRect {
    public:
        int Center() {
            return (this->maxx + this->minx) / 2;
        }

    public:
        int miny;
        int minx;
        int maxy;
        int maxx;
    };
}


