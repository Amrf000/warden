// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CIRECT_H
#define ENGINE_CIRECT_H

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

#endif //ENGINE_CIRECT_H
