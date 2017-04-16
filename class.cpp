#include <iostream>
#define length 3
#define width 3

class Matrix;

class Vector { //write it in h - file
        double x, y, z;
    public: 
        double get_x();
        double get_y();
        double get_z();
        void set_x(double a);
        void set_y(double b);
        void set_z(double c);
        Vector(double a, double b, double c);
        Vector();
        Vector(double a);
        Vector add(Vector A);
        Vector sub(Vector A);
        Vector mul(double a);
        friend Vector operator* (Matrix A, Vector B);
        friend Vector sum (Vector X, Vector Y);
        friend Vector operator+ (Vector A, Vector B);
        friend Vector operator* (Vector A, Vector B);
        friend Vector operator* (Vector A, double b);
        friend std::ostream & operator<< (std::ostream &os, Vector A);
        friend std::istream & operator>> (std::istream &os, Vector &A);
        double mul(Vector A);
        Vector vectMul(Vector A);
        double absolute();
};

double Vector::get_x(){
    return x;
}

double Vector::get_y(){
    return y;
}

double Vector::get_z(){
    return z;
}

void Vector::set_x(double a){
    x = a;
}

void Vector::set_y(double b){
    y = b;
}

void Vector::set_z(double c){
    z = c;
}

Vector::Vector(double a, double b, double c){
    x = a;
    y = b;
    z = c;
}

Vector::Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double a){
    x = a;
    y = 0;
    z = 0;
}

Vector Vector::sub(Vector A){
    return Vector (x - A.get_x(), y - A.get_y(), z - A.get_z());
}

Vector operator+ (Vector A, Vector B){
    return Vector(B.get_x() + A.get_x(), B.get_y() + A.get_y(), B.get_z() + A.get_z());
}

Vector operator* (Vector A, Vector B){
    return Vector(B.get_x() * A.get_y(), B.get_y() * A.get_y(), B.get_z() * A.get_z());
}

Vector operator* (Vector A, double b){
    return Vector(b * A.get_x(), b * A.get_y(), b * A.get_z());
}

std::ostream & operator << (std::ostream &os, Vector A){
    os << A.get_x() << A.get_y() << A.get_z() << std::endl;
    return os;
}

std::istream & operator >> (std::istream &os, Vector &A){
    double a, b, c;
    os >> a >> b >> c;
    A.set_x(a);
    A.set_y(b);
    A.set_z(c);
    return os;
}

Vector Vector::vectMul(Vector A){
    return Vector (y * A.get_z() - z * A.get_y(), z * A.get_x() - x * A.get_z(), x * A.get_y() - y * A.get_x());
}

double Vector::absolute() {
    return x * x + y * y + z * z;
}    
    
class Matrix{
private:
    double ** elem;
public:
    Matrix();
    ~Matrix();
    friend Vector operator* (Matrix &A, Vector &B);
    friend Matrix operator+ (Matrix A, Matrix B);
    friend std::ostream & operator << (std::ostream &os, Matrix A);
    void set_elem(int a, int b, double c);
    double get_elem(int a, int b);
};

Matrix::Matrix(){
    elem = new double * [length];
    for (int i = 0; i < length; i++){
        elem[i] = new double[width];
        for (int j = 0; j < width; j++){
            elem[i][j] = i * 3 + j;
        }
    }
}

Matrix::~Matrix(){
    delete[] elem;
    elem = NULL;
}

void Matrix::set_elem(int a, int b, double c){
    this->elem[a][b] = c;
}

double Matrix::get_elem(int a, int b){
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

Vector operator* (Matrix &A, Vector &B){
    return Vector(A.get_elem(0, 0) * B.get_x() + A.get_elem(0, 1) * B.get_y() +A.get_elem(0, 2) * B.get_z(),
                  A.get_elem(1, 0) * B.get_x() + A.get_elem(1, 1) * B.get_y() +A.get_elem(1, 2) * B.get_z(),
                  A.get_elem(2, 0) * B.get_x() + A.get_elem(2, 1) * B.get_y() +A.get_elem(2, 2) * B.get_z());
}

std::ostream & operator << (std::ostream &os, Matrix A){
    double c = 0;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            c = A.get_elem(i, j);
            os << c << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

int main(){
    Vector * A = new Vector();
    std::cin >> *A;
    std::cout << (*A);
    Matrix * B = new Matrix();
    std::cout << (*B);
    Vector * C = new Vector();
    (*C) = (*B) * (*A);
    return 0;
}

