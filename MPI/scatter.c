#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main (int argc, char *argv[]){
int numtasks, rank, sendcount, recvcount, source;
char sendbuf[SIZE][SIZE] = {
{'A','P','U','R', 'V'},
{'A','P','U','R', 'V'},
{'A','P','U','R', 'V'},
{'A','P','U','R', 'V'},
{'A','P','U','R', 'V'}};
char recvbuf[SIZE];
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
if (numtasks == SIZE) {
source = 0;
sendcount = SIZE;
recvcount = SIZE;
MPI_Scatter(sendbuf,sendcount,MPI_CHAR,recvbuf,recvcount,
MPI_CHAR,source,MPI_COMM_WORLD);
printf("rank= %d Results: %c %c %c %c %c\n",rank,recvbuf[0],
recvbuf[1],recvbuf[2],recvbuf[3], recvbuf[4]); }
else
printf("Must specify %d processors. Terminating.\n",SIZE);
MPI_Finalize();
}
