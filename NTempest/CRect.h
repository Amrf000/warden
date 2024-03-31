#pragma once


namespace NTempest {
    class C2Vector;

    class CRect {
    public:
        static CRect Intersection(const CRect &l, const CRect &r);

        CRect();

        CRect(float miny, float minx, float maxy, float maxx);

        bool operator==(CRect &rect);

        bool IsPointInside(const C2Vector &pt);

        CRect *Clamp(C2Vector &a2);

    public:
        float minY;
        float minX;
        float maxY;
        float maxX;
    };

    //bool operator==(const CRect &rectA, const CRect &rectB);
}


