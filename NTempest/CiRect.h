#pragma once

namespace NTempest {
    class CiRect {
    public:
        CiRect() {}

        CiRect(int miny,
               int minx,
               int maxy,
               int maxx) : minx(minx), miny(miny), maxx(maxx), maxy(maxy) {}

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


