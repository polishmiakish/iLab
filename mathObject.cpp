#include <iostream>

class MathObject{
    protected:
        double x, y, z;
    public:
        virtual MathObject operator+(void * a, void * b);
        virtual get_x();
        virtual get_y();
        virtual get_z();
}
