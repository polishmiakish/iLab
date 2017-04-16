#include "ShablonVector.cpp"

int main(){
    Vector<int>* A = new Vector<int>(1, 2, 3);
    Vector<double>* B = new Vector<double> (0.1, 0.4, 0.7);
    std::cout << *A;
    std::cout << *B;
    return 0;
}
