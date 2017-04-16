#include "class.h"

int main(){
    Vector * A = new Vector(1, 2, 3);
    //std::cin >> *A;
    Matrix * B = new Matrix();
    std::cout << (*B * *A);
    return 0;
}

