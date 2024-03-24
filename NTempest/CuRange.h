// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_CURANGE_H
#define ENGINE_CURANGE_H


namespace NTempest {
    class CuRange {
    public:
        CuRange(unsigned int *a2, unsigned int *a3) {
            this->min = *a2;
            this->max = *a3;
        }

        CuRange *ClampClosed(float *a2, float *a3) {
            float *v3;

            v3 = a2;
            if (*a2 <= *a3) {
                v3 = a2 + 1;
                if (*a3 <= a2[1])
                    v3 = a3;
            }
            this->min = *(unsigned int *) v3;
            return this;
        }

        int Value(int a1, float *a2) {
            char v3[4];
            int v4[3];

            sub_D546C(v4, a2 + 1, a2);
            sub_5E602C(v3);
            sub_D560C((unsigned int *) a1, (unsigned int *) a2, (unsigned int *) v3);
            return a1;
        }

        bool InClosedRange(float *a2) {
            return *a2 >= *(float *) &this->min && *(float *) &this->max >= *a2;
        }

    public:
        unsigned int min;
        unsigned int max;
    };
}


#endif //ENGINE_CURANGE_H
