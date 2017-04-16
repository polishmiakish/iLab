#include <iostream>
#include <time.h>
#include <omp.h>
#define N 100
#define M 10

int main(){
    int A[N][N];
    int B[N][N];
    int C[N][N];
    double a = omp_get_wtime();
    omp_set_num_threads(2);
#pragma omp parallel for
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                A[i][j] = (i + j) % M;
            }
        }
#pragma omp parallel for
        for (int k = 0; k < N; k++){
            for (int l = 0; l < N; l++){
                B[k][l] = (k + l) % M;
            }
        }
#pragma omp parallel for
        for (int m = 0; m < N; m++){
            for (int n = 0; n < N; n++){
                C[m][n] = A[m][n] + B[m][n];
            }
        }
    double b = omp_get_wtime();
    std::cout << "finish " << (b - a) << std::endl;
    return 0;
}
