#include <iostream>
#include <time.h>
#include <omp.h>
#define N 500000
#define M 100

int main(){
    int A[N];
    int B[N];
    int C[N];
    double a = omp_get_wtime();
    omp_set_num_threads(2);
#pragma omp parallel for
        for (int i = 0; i < N; i++){
            A[i] = i % M;
        }
#pragma omp parallel for
        for (int j = 0; j < N; j++){
            B[j] = j % M;
        }
#pragma omp parallel for
        for (int k = 0; k < N; k++){
            C[k] = A[k] + B[k];
        }
    double b = omp_get_wtime();
    std::cout << "finish " << (b - a) << std::endl;
    return 0;
}
