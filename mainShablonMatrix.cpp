#include "shablonMatrix.cpp"

int main(){
    Matrix<int, 3> *C = new Matrix<int, 3>();
    std::cout << *C;
    std::cout << (*C + *C);
    return 0;
}
