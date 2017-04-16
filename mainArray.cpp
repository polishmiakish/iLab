#include "shablonArray.cpp"

int main(){
    Vector<int, 3> * A = new Vector<int, 3> (1, 2, 3);
    Vector<double, 3> * B = new Vector<double, 3> (0.5, 0.7, 0.33);
    std::cout << *B;
    std::cout << * A;
    return 0;
}
