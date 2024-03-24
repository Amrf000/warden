//
// Created by liuyawu on 2019/5/9.
//

#ifndef ENGINE_C22UMATRIX_H
#define ENGINE_C22UMATRIX_H
namespace NTempest {
    class C22uMatrix {
    public:
        C22uMatrix(unsigned int *a2, unsigned int *a3, unsigned int *a4, unsigned int *a5) {
            this->a1 = *a2;
            this->a2 = *a3;
            this->a3 = *a4;
            this->a4 = *a5;
        }

    public:
        unsigned int a1;
        unsigned int a2;
        unsigned int a3;
        unsigned int a4;
    };
}

#endif //ENGINE_C22UMATRIX_H
