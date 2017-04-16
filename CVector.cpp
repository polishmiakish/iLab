/* main.cpp
 * func_from_main.h
 * class.cpp
 * class.h */
#include <iostream>
#include "drob.cpp"

class Matrix;
class Vector { //write it in h - file
        Drob * x = new Drob (1, 2);
        Drob * y = new Drob (3, 4);
        Drob * z = new Drob (5, 6);
    public: 
        Drob get_x();
        Drob get_y();
        Drob get_z();
        void set_x(Drob a);
        void set_y(Drob b);
        void set_z(Drob c);
        Vector(Drob a, Drob b, Drob c);
        Vector add(Vector A);
        Vector sub(Vector A);
        Vector mul(Drob a);
        friend Vector operator* (Matrix A, Vector B);
        friend Vector sum (Vector X, Vector Y);
        friend Vector operator+ (Vector A, Vector B);
        friend Vector operator* (Vector A, Vector B);
        friend Vector operator* (Vector A, Drob b);
        friend std::ostream & operator<< (std::ostream &os, Vector A);
        friend std::istream & operator>> (std::istream &os, Vector A);
        Vector vectMul(Vector A);
        Drob absolute();
};

Drob Vector::get_x(){
    return *x;
}

Drob Vector::get_y(){
    return *y;
}

Drob Vector::get_z(){
    return *z;
}

void Vector::set_x(Drob a){
    *x = a;
}

void Vector::set_y(Drob b){
    *y = b;
}

void Vector::set_z(Drob c){
    *z = c;
}

Vector::Vector(Drob a, Drob b, Drob c){
    *x = a;
    *y = b;
    *z = c;
}

Vector Vector::sub(Vector A){
    return Vector (*x - A.get_x(), *y - A.get_y(), *z - A.get_z());
}

Vector operator+ (Vector A, Vector B){
    return Vector(B.get_x() + A.get_x(), B.get_y() + A.get_y(), B.get_z() + A.get_z());
}

Vector operator* (Vector A, Vector B){
    return Vector(B.get_x() * A.get_y(), B.get_y() * A.get_y(), B.get_z() * A.get_z());
}

Vector operator* (Vector A, Drob b){
    return Vector(b * A.get_x(), b * A.get_y(), b * A.get_z());
}

std::ostream & operator << (std::ostream &os, Vector A){
    os << A.get_x() << A.get_y() << A.get_z() << std::endl;
    return os;
}

std::istream & operator >> (std::istream &os, Vector *A){
    Drob * a = new Drob (1, 2);
    Drob * b = new Drob (3, 4);
    Drob * c = new Drob (5, 6);
    os >> *a >> *b >> *c;
    A->set_x(*a);
    A->set_y(*b);
    A->set_z(*c);
    return os;
}

Vector Vector::vectMul(Vector A){
    return Vector (*y * A.get_z() - *z * A.get_y(), *z * A.get_x() - *x * A.get_z(), *x * A.get_y() - *y * A.get_x());
}

Drob Vector::absolute() {
    return *x * *x + *y * *y + *z * *z;
}
