#include <iostream>
#include <time.h>
#include <omp.h>
#include <math.h>
#define N 1000000

int main(){
    double x0 = 0;
    double y0 = 1;
    double S[N];
    double T = 0;
    double a = omp_get_wtime();
//#pragma omp parallel for
    for (int i = 0; i < N; i++){
        T = T + y0 * (1/(double)N);
        x0 = (double)((double)i/(double)N);
        y0 = sqrt(1 - x0 * x0);
    }

    for (int i = 1; i < N; i++){
        S[0] += S[i];
    } 
    double b = omp_get_wtime();
    std::cout << 4 * T << std::endl;
    std::cout << "time = " << (b - a) << std::endl;
    return 0;
}
