#include "circle.cpp"

int main(){
    Vector * A = new Vector(1, 2, 3);
    std::cout << *A << std::endl;
    Circle * B = new Circle(9, 4, 5, *A);
    std::cout << *B;
    return 0;
}
