#pragma once

#include "C3Vector.h"

namespace NTempest {
    class C33Matrix {
    public:
        C33Matrix *Inverse(int a2) {
            NTempest::C33Matrix v3;

            sub_553C8C(a2);
            sub_5542BC(&v3);
            *this = v3;
            return this;
        }

        long double sub_553C8C(float *a1) {
            return (float) ((float) ((float) ((float) ((float) ((float) ((float) (*a1 * a1[4]) * a1[8])
                                                                + (float) ((float) (a1[5] * a1[1]) * a1[6]))
                                                       + (float) ((float) (a1[3] * a1[2]) * a1[7]))
                                              - (float) (a1[6] * (float) (a1[4] * a1[2])))
                                     - (float) (a1[8] * (float) (a1[1] * a1[3])))
                            - (float) (a1[7] * (float) (*a1 * a1[5])));
        }

        NTempest::C33Matrix *sub_5542BC() {
            NTempest::C33Matrix v2;
            int v3[26];

            sub_55418C(v3);
            v3[15] = v3[0];
            v3[16] = v3[1];
            v3[17] = v3[2];
            v3[18] = v3[3];
            v3[19] = v3[4];
            v3[20] = v3[5];
            v3[21] = v3[6];
            v3[22] = v3[7];
            v3[23] = v3[8];
            NTempest::operator*(&v2);
            *this = v2;
            return this;
        }

        NTempest::C33Matrix *sub_55418C(NTempest::C33Matrix *that) {
            v3 = that->a5;
            v9 = that->a4;
            v10 = that->a2;
            v11 = that->a1;
            v4 = that->a8;
            v5 = that->a7;
            v6 = that->a6;
            v7 = that->a3;
            v8 = that->a9;
            this->a1 = (float) (v3 * v8) - (float) (v4 * v6);
            this->a2 = -(float) ((float) (v10 * v8) - (float) (v4 * v7));
            this->a3 = (float) (v10 * v6) - (float) (v3 * v7);
            this->a4 = -(float) ((float) (v9 * v8) - (float) (v5 * v6));
            this->a5 = (float) (v8 * v11) - (float) (v5 * v7);
            this->a6 = -(float) ((float) (v6 * v11) - (float) (v7 * v9));
            this->a7 = (float) (v9 * v4) - (float) (v3 * v5);
            this->a8 = -(float) ((float) (v4 * v11) - (float) (v5 * v10));
            this->a9 = (float) (v3 * v11) - (float) (v9 * v10);
            return this;
        }

    public:
        C3Vector columns[3];
    };
}


