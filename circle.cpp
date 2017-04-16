#include "Dot.cpp"

class Circle : public Dot {
    Vector A;
    public:
        Circle() : Dot(){
            A = Vector(0, 0, 0);
        }
        Circle(double a, double b, double c, Vector B) : Dot(a, b, c) {
            A = B;
        }
        friend std::ostream &operator<< (std::ostream &os, Circle A);
};

std::ostream &operator<< (std::ostream &os, Circle A){
    os << A.A << " " << A.x << " " <<  A.y << " " << A.z;
    return os;
}
