#include <iostream>
#include "mathObject.cpp"

class Dot {
    protected:
        double x, y, z;
    public:
        Dot();
        Dot(double a, double b, double c);
        friend std::ostream &operator<< (std::ostream & os, Dot A);
};

Dot::Dot(){
    x = 0;
    y = 0;
    z = 0;
}

Dot::Dot(double a, double b, double c){
    x = a;
    y = b;
    z = c;
}

std::ostream &operator<< (std::ostream & os, Dot A){
    os << A.x << " " << A.y << " " << A.z;
    return os;
}

class Vector: public Dot {
    public:
        Vector() : Dot(){}
        Vector (double a, double b, double c) : Dot(a, b, c){}
        friend std::ostream &operator<< (std::ostream & os, Vector A);
};

std::ostream &operator<< (std::ostream & os, Vector A){
    os << A.x << " " << A.y << " " << A.z;
    return os;
}
