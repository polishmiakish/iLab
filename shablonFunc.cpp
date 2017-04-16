#include <iostream>

template <typename T>

T sum (T x, T y){
    return x + y;
}

double divide(double a, double b){
    try {
        if (b == 0)
            throw 1;
        return a/b;
    }
    catch(int a){
        
    }
}

int main(){
    double x = 765.876;
    double y = 1.676597;
    std::cout << sum<double> (x, y) << std::endl;
    return 0;
}
