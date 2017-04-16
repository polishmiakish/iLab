#include <iostream>
#include "CVector.cpp"
#define length 3
#define width 3

class Matrix{
private:
    Drob ** elem;
public:
    Matrix();
    ~Matrix();
    friend Vector operator* (Matrix A, Vector B);
    friend Matrix operator+ (Matrix A, Matrix B);
    friend std::ostream & operator << (std::ostream &os, Matrix A);
    void set_elem(int a, int b, Drob c);
    Drob get_elem(int a, int b);
};

Matrix::Matrix(){
    elem = new Drob * [length];
    for (int i = 0; i < length; i++){
        elem[i] = new Drob[width]; 
        for (int j = 0; j < width; j++){
            elem[i][j] = new Drob((i + 1)* 3, 1 + j);
        }
    }
}

Matrix::~Matrix(){
    delete[] elem;
    elem = NULL;
}

void Matrix::set_elem(int a, int b, Drob c){
    this->elem[a][b] = c;
}

Drob Matrix::get_elem(int a, int b){
    return this->elem[a][b];
}

Matrix operator+ (Matrix A, Matrix B){
    Matrix *C = new Matrix();
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            A.set_elem(i, j, A.get_elem(i, j) + B.get_elem(i, j));
        }
    }
    return *C;
}

Vector operator* (Matrix A, Vector B){
    return Vector(A.get_elem(0, 0) * B.get_x() + A.get_elem(0, 1) * B.get_y() +A.get_elem(0, 2) * B.get_z(),
                  A.get_elem(1, 0) * B.get_x() + A.get_elem(1, 1) * B.get_y() +A.get_elem(1, 2) * B.get_z(),
                  A.get_elem(2, 0) * B.get_x() + A.get_elem(2, 1) * B.get_y() +A.get_elem(2, 2) * B.get_z());
}


std::ostream & operator << (std::ostream &os, Matrix A){
    Drob * c = new Drob(1, 2);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            *c = A.get_elem(i, j);
            os << *c << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

