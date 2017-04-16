#include <mpi.h>

int main(int argc, char ** argv){
    MPI_Init(&argc, &argv);
    MPI_Comm_size(); //число узлов
    MPI_Comm_rank(); // номер текущего узла
    MPI_Finalize();
}
