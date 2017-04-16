//3. Шаблон класса комплексного числа, в качестве а и б может быть вектор, вещественное число, дробь и т.д. Реализовать сложение, вычитание, умножение, умножение на
// число, модуль

#include <iostream>

template <typename T>

class Complex{
public:
    T a, b;
    Complex(){
        a = 0;
        b = 0;
    }
    Complex(T x, T y){
        a = x;
        b = y;
    }
    void complexDump(){
        std::cout << a << " + i * " << b << std::endl;
    }
    template <typename Type> friend Complex<Type> operator+ (Complex<T> A, Complex<T> B);
    template <typename Type> friend Complex<Type> operator* (Complex<T> A, float a);
    template <typename Type> friend Complex<Type> operator- (Complex<T> A, Complex<T> B);
    template <typename Type> friend Complex<Type> operator* (Complex<T> A, Complex<T> B);
    float squarModul(){
        return (a * a + b * b);
    }

};

template <typename Type> Complex<Type> operator+ (Complex<Type> A, Complex<Type> B){
    return Complex<Type>(A.a + B.a, A.b + B.b);
}

template <typename Type> Complex<Type> operator- (Complex<Type> A, Complex<Type> B){
    return Complex<Type>(A.a - B.a, A.b - B.b);
}

template <typename Type> Complex<Type> operator* (Complex<Type> A, Complex<Type> B){
    return Complex<Type>(A.a * B.a - A.b * B.b, A.a * B.b + A.b * B.a);
}

template <typename Type> Complex<Type> operator* (Complex<Type> A, float a){
    return Complex<Type>(A.a * a, A.b * a);
}

int main(){
    Complex<float> * A = new Complex<float>(1, 2);
    Complex<float> * B = new Complex<float>(3, 4);
    (*A).complexDump();
    (*B).complexDump();
    (*A + *B).complexDump();
    (*A - *B).complexDump();
    (*A * *B).complexDump();
    (*A * 15.5).complexDump();
    std::cout << (*A).squarModul() << std::endl;
    return 0;
}
