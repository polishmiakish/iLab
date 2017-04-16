#include <iostream>

template <typename T, int length>
class Matrix;
class Vector{
        T x[length];
    public:
        Vector(T a, T b, T c){
                x[0] = a;
                x[1] = b;
                x[2] = c;
        }
        template <typename Type, int len> friend Vector<Type, 3> operator+ (Vector<T, 3> A, Vector<T, 3> B);
        template <typename Type, int len> friend Vector<T, 3> operator* (Vector<T, 3> A, Vector<T, 3> B);
        template <typename Type, int len> friend Vector<T, 3> operator* (Vector<T, 3> A, T b);
        template <typename Type, int len> friend std::ostream & operator<< (std::ostream &os, Vector<T, 3> A);
        template <typename Type, int len> friend std::istream & operator>> (std::istream &os, Vector<T, 3> A);
};

template <typename Type, int length>
Vector<Type, 3> operator+ (Vector<Type, 3> A, Vector<Type, 3> B){
    return Vector<Type, 3>(B.x[0] + A.x[0], B.x[1] + A.x[1], B.x[2] + A.x[2]);
}

template <typename Type>
Vector<Type, 3> operator* (Vector<Type, 3> A, Vector<Type, 3> B){
    return Vector<Type, 3>(B.x[0] * A.x[0], B.x[1] * A.x[1], B.x[2] * A.x[2]);

}

template <typename Type>
Vector<Type, 3> operator* (Vector<Type, 3> A, Type b){
    return Vector<Type, 3>(b * A.x[0], b * A.x[1], b * A.x[2]);
}

template <typename Type>
std::ostream & operator << (std::ostream &os, Vector<Type, 3> A){
    os << A.x[0] << A.x[1] << A.x[2] << std::endl;
    return os;
}

template <typename Type>
std::istream & operator >> (std::istream &os, Vector<Type, 3> *A){
    Type a, b, c;
    os >> a >> b >> c;
    A->x[0] = a;
    A->x[1] = b;
    A->x[2] = c;
    return os;
}


