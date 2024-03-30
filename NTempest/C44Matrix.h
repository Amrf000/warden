#pragma once

#include "C4Vector.h"

namespace NTempest {
    class C44Matrix {
    public:
        C44Matrix *Inverse() {
            C44Matrix v3;

            int a2 = sub_2E71D6();
            sub_2E9A04(&v3);
            *this = v3;
            return this;
        }

        long double sub_2E71D6() {
            v12 = this->a16;
            v13 = this->a15;
            v14 = this->a14;
            v1 = this->a12;
            v2 = this->a11;
            v3 = this->a10;
            v4 = this->a8;
            v5 = this->a7;
            v15 = this->a6 * v2;
            v6 = v1 * v5;
            v16 = v3 * v4;
            v17 = v3 * v5;
            v7 = this->a9;
            v8 = this->a5;
            v9 = v5 * v7;
            v10 = v3 * v8;
            v18 = v7 * this->a6;
            return (float) ((float) ((float) (
                    (float) ((float) ((float) ((float) ((float) ((float) ((float) (v12 * v15) + (float) (v14 * v6))
                                                                 + (float) (v13 * v16))
                                                        - (float) (v14 * (float) (v2 * v4)))
                                               - (float) (v12 * v17))
                                      - (float) (v13 * (float) (this->a6 * v1)))
                             * this->a1)
                    - (float) ((float) ((float) ((float) ((float) ((float) ((float) (v12 * (float) (v2 * v8))
                                                                            + (float) (v6 * this->a13))
                                                                   + (float) (v13 * (float) (v4 * v7)))
                                                          - (float) ((float) (v2 * v4) * this->a13))
                                                 - (float) (v12 * v9))
                                        - (float) (v13 * (float) (v1 * v8)))
                               * this->a2))
                                     + (float) ((float) ((float) ((float) ((float) ((float) ((float) (v12 * v10)
                                                                                             + (float) (
                    (float) (this->a6 * v1) * this->a13))
                                                                                    + (float) ((float) (v4 * v7) * v14))
                                                                           - (float) (v16 * this->a13))
                                                                  - (float) (v12 * v18))
                                                         - (float) ((float) (v1 * v8) * v14))
                                                * this->a3))
                            - (float) (
                    (float) ((float) ((float) ((float) ((float) ((float) (v10 * v13) + (float) (v15 * this->a13))
                                                        + (float) (v9 * v14))
                                               - (float) (v17 * this->a13))
                                      - (float) (v13 * v18))
                             - (float) (v14 * (float) (v2 * v8)))
                    * this->a4));
        }

        C44Matrix *sub_2E9A04() {
            C44Matrix v2;
            int v3[34];

            sub_2E90CC(v3);
            v3[16] = v3[0];
            v3[17] = v3[1];
            v3[18] = v3[2];
            v3[19] = v3[3];
            v3[20] = v3[4];
            v3[21] = v3[5];
            v3[22] = v3[6];
            v3[23] = v3[7];
            v3[24] = v3[8];
            v3[25] = v3[9];
            v3[26] = v3[10];
            v3[27] = v3[11];
            v3[28] = v3[12];
            v3[29] = v3[13];
            v3[30] = v3[14];
            v3[31] = v3[15];
            sub_2E8384(&v2);
            *this = v2;
            return this;
        }

        C44Matrix *sub_2E8384(C44Matrix *a2, float a3) {
            this->a16 = a3 * a2->a16;
            this->a15 = a3 * a2->a15;
            this->a14 = a3 * a2->a14;
            this->a13 = a3 * a2->a13;
            this->a12 = a3 * a2->a12;
            this->a11 = a3 * a2->a11;
            this->a10 = a3 * a2->a10;
            this->a9 = a3 * a2->a9;
            v4 = a3 * a2->a8;
            v5 = a3 * a2->a7;
            v6 = a3 * a2->a6;
            v7 = a3 * a2->a5;
            v8 = a3 * a2->a4;
            v9 = a3 * a2->a3;
            v10 = a3 * a2->a2;
            this->a1 = a3 * a2->a1;
            this->a2 = v10;
            this->a3 = v9;
            this->a4 = v8;
            this->a5 = v7;
            this->a6 = v6;
            this->a7 = v5;
            this->a8 = v4;
            return this;
        }

        C44Matrix *sub_2E90CC(C44Matrix *a2) {
            v13 = a2->a11;
            v14 = a2->a10;
            v15 = a2->a9;
            v3 = a2->a7;
            v4 = a2->a6;
            v5 = a2->a5;
            v6 = a2->a3;
            v12 = a2->a2;
            v7 = a2->a1;
            v16 = v4 * a2->a1;
            v17 = v12 * v3;
            v18 = v4 * v6;
            v19 = v3 * a2->a1;
            v20 = a2->a15;
            v21 = a2->a14;
            v22 = a2->a13;
            v23 = v13 * v4;
            v24 = v15 * v3;
            v25 = v14 * v3;
            v26 = v15 * v4;
            v27 = a2->a12;
            v8 = a2->a8;
            v9 = a2->a4;
            v28 = v4 * v9;
            v29 = a2->a16;
            v30 = v4 * v27;
            v10 = v3 * v9;
            v11 = v3 * v27;
            this->a1 = (float) ((float) (
                    (float) ((float) ((float) (v23 * v29) + (float) (v21 * v11)) + (float) (v20 * (float) (v14 * v8)))
                    - (float) (v21 * (float) (v8 * v13)))
                                - (float) (v25 * v29))
                       - (float) (v20 * v30);
            LODWORD(this->a2) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) ((float) (v13 * v12) * v29)
                                                        + (float) (v21 * (float) (v6 * v27)))
                                               + (float) (v20 * (float) (v14 * v9)))
                                      - (float) (v21 * (float) (v9 * v13)))
                             - (float) ((float) (v14 * v6) * v29))
                    - (float) (v20 * (float) (v12 * v27))) ^ unk_A7F250;
            this->a3 = (float) ((float) (
                    (float) ((float) ((float) (v17 * v29) + (float) (v21 * (float) (v6 * v8))) + (float) (v20 * v28))
                    - (float) (v21 * v10))
                                - (float) (v18 * v29))
                       - (float) (v20 * (float) (v12 * v8));
            LODWORD(this->a4) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) (v17 * v27) + (float) (v14 * (float) (v6 * v8)))
                                               + (float) (v13 * v28))
                                      - (float) (v14 * v10))
                             - (float) (v18 * v27))
                    - (float) (v13 * (float) (v12 * v8))) ^ unk_A7F250;
            LODWORD(this->a5) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) ((float) (v13 * v5) * v29) + (float) (v11 * v22))
                                               + (float) (v20 * (float) (v15 * v8)))
                                      - (float) (v22 * (float) (v8 * v13)))
                             - (float) (v24 * v29))
                    - (float) (v20 * (float) (v5 * v27))) ^ unk_A7F250;
            this->a6 = (float) (
                    (float) ((float) ((float) ((float) ((float) (v13 * v7) * v29) + (float) (v22 * (float) (v6 * v27)))
                                      + (float) (v20 * (float) (v15 * v9)))
                             - (float) (v22 * (float) (v9 * v13)))
                    - (float) ((float) (v15 * v6) * v29))
                       - (float) (v20 * (float) (v7 * v27));
            LODWORD(this->a7) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) (v19 * v29) + (float) (v22 * (float) (v6 * v8)))
                                               + (float) (v20 * (float) (v5 * v9)))
                                      - (float) (v22 * v10))
                             - (float) ((float) (v5 * v6) * v29))
                    - (float) (v20 * (float) (v7 * v8))) ^ unk_A7F250;
            this->a8 = (float) ((float) ((float) ((float) ((float) (v19 * v27) + (float) (v15 * (float) (v6 * v8)))
                                                  + (float) (v13 * (float) (v5 * v9)))
                                         - (float) (v15 * v10))
                                - (float) ((float) (v5 * v6) * v27))
                       - (float) (v13 * (float) (v7 * v8));
            this->a9 = (float) ((float) ((float) ((float) ((float) ((float) (v14 * v5) * v29) + (float) (v22 * v30))
                                                  + (float) (v21 * (float) (v15 * v8)))
                                         - (float) (v22 * (float) (v14 * v8)))
                                - (float) (v26 * v29))
                       - (float) (v21 * (float) (v5 * v27));
            LODWORD(this->a10) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) ((float) (v14 * v7) * v29)
                                                        + (float) (v22 * (float) (v12 * v27)))
                                               + (float) (v21 * (float) (v15 * v9)))
                                      - (float) (v22 * (float) (v14 * v9)))
                             - (float) ((float) (v15 * v12) * v29))
                    - (float) (v21 * (float) (v7 * v27))) ^ unk_A7F250;
            this->a11 = (float) ((float) ((float) ((float) ((float) (v16 * v29) + (float) (v22 * (float) (v12 * v8)))
                                                   + (float) (v21 * (float) (v5 * v9)))
                                          - (float) (v22 * v28))
                                 - (float) ((float) (v12 * v5) * v29))
                        - (float) (v21 * (float) (v7 * v8));
            LODWORD(this->a12) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) (v16 * v27) + (float) (v15 * (float) (v12 * v8)))
                                               + (float) (v14 * (float) (v5 * v9)))
                                      - (float) (v15 * v28))
                             - (float) ((float) (v12 * v5) * v27))
                    - (float) (v14 * (float) (v7 * v8))) ^ unk_A7F250;
            this->a13 = -(float) (
                    (float) ((float) ((float) ((float) ((float) (v20 * (float) (v14 * v5)) + (float) (v22 * v23))
                                               + (float) (v21 * v24))
                                      - (float) (v22 * v25))
                             - (float) (v20 * v26))
                    - (float) (v21 * (float) (v13 * v5)));
            this->a14 = (float) (
                    (float) ((float) ((float) ((float) (v20 * (float) (v14 * v7)) + (float) (v22 * (float) (v13 * v12)))
                                      + (float) (v21 * (float) (v15 * v6)))
                             - (float) (v22 * (float) (v14 * v6)))
                    - (float) (v20 * (float) (v15 * v12)))
                        - (float) (v21 * (float) (v13 * v7));
            LODWORD(this->a15) = COERCE_UNSIGNED_INT(
                    (float) ((float) ((float) ((float) ((float) (v16 * v20) + (float) (v17 * v22))
                                               + (float) ((float) (v5 * v6) * v21))
                                      - (float) (v18 * v22))
                             - (float) ((float) (v12 * v5) * v20))
                    - (float) (v19 * v21)) ^ unk_A7F250;
            this->a16 = (float) ((float) (
                    (float) ((float) ((float) (v13 * v16) + (float) (v15 * v17)) + (float) (v14 * (float) (v5 * v6)))
                    - (float) (v15 * v18))
                                 - (float) (v13 * (float) (v12 * v5)))
                        - (float) (v14 * v19);
            return this;
        }

    public:
        C4Vector columns[4];
    };
}


