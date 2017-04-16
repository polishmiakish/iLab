#include <iostream>

template <typename Type>

class Vector { //write it in h - file
        Type x, y, z;
    public: 
        Type get_x(){
            return x;
        }
        Type get_y(){
            return y;
        }
        Type get_z(){
            return z;
        }
        void set_x(Type a){
            x = a;
        }
        void set_y(Type b){
            y = b;
        }
        void set_z(Type c){
            z = c;
        }
        Vector(Type a, Type b, Type c){
            x = a;
            y = b;
            z = c;
        }
        template <typename T> friend Vector<T> operator+ (Vector<T> A, Vector<T> B);
        template <typename T> friend Vector<T> operator* (Vector<T> A, Vector<T> B);
        template <typename T> friend Vector<T> operator* (Vector<T> A, T b);
        template <typename T> friend std::ostream & operator<< (std::ostream &os, Vector<T> A);
        template <typename T> friend std::istream & operator>> (std::istream &os, Vector<T> A);
};
template <typename Type>
Vector<Type> operator+ (Vector<Type> A, Vector<Type> B){
    return Vector<Type>(B.get_x() + A.get_x(), B.get_y() + A.get_y(), B.get_z() + A.get_z());
}
template <typename Type>
Vector<Type> operator* (Vector<Type> A, Vector<Type> B){
    return Vector<Type>(B.get_x() * A.get_y(), B.get_y() * A.get_y(), B.get_z() * A.get_z());
}
template <typename Type>
Vector<Type> operator* (Vector<Type> A, Type b){
    return Vector<Type>(b * A.get_x(), b * A.get_y(), b * A.get_z());
}

template <typename Type>
std::ostream & operator << (std::ostream &os, Vector<Type> A){
    os << A.get_x() << A.get_y() << A.get_z() << std::endl;
    return os;
}
template <typename Type>
std::istream & operator >> (std::istream &os, Vector<Type> *A){
    Type a, b, c;
    os >> a >> b >> c;
    A->set_x(a);
    A->set_y(b);
    A->set_z(c);
    return os;
}
