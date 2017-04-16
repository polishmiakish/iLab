#include <omp.h>
#include <iostream>
#include <stdio.h>

int main(){
    omp_set_num_threads(10);
#pragma omp parallel 
{
    printf("\nNumber of threads = %d", omp_get_num_threads());
    printf("\nThread number = %d", omp_get_thread_num());
}
    omp_get_num_threads();
    double n;
    std::cin >> n;
    std::cout << "\nnotHello" << std::endl;
    return 0;
}
