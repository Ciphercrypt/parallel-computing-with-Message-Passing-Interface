#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int main (int argc, char *argv[])
{
int rank,numtasks,array[6] = {100,600,300,800,250,720},i,inputNumber;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
printf("Local Input for process %d is %d\n",rank,array[rank]);
inputNumber = array[rank];
int maxNumber;
MPI_Reduce(&inputNumber, &maxNumber, 1, MPI_INT, MPI_MAX, 0,
MPI_COMM_WORLD);
// Print the result
if (rank == 0) {
printf("Maximum of all is: %d\n",maxNumber);
}
MPI_Finalize();
}
