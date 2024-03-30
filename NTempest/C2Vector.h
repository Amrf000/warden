#pragma once

#include <math.h>


namespace NTempest {
    class C2Vector {
    public:
	    C2Vector() {
			x = 0.0f;
			y = 0.0f;
	    }
    	C2Vector(float x, float y): x(x), y(y) {}
    	
    	bool operator==(const C2Vector& v) {
    		return this->x == v.x && this->y == v.y;
		}

    	
        long double Mag() {
            return sqrtf((float) (this->x * this->x) + (float) (this->y * this->y));
        }

        int FromAxisAngle(float a2) {
            sinf(x);
            v3 = cosf(x);
            *(float *) &result = a2 * v3;
            return result;
        }

        void AxisAngle() {
            long double a = Mag();
            sub_659E20(&this->x, (float) a);
        }

    public:
        float x;
        float y;
    };
}


