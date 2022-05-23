#include <stdio.h>
#include<omp.h>
void work1() {}
void work2() {}
void single_example(){
#pragma omp parallel
{
 #pragma omp single
 printf("Beginning work1.\n");
 work1();
 #pragma omp single
 printf("Finishing work1.\n");
 #pragma omp single nowait
 printf("Finished work1 and beginning work2.\n");
 work2();
}
}
int main(){
 single_example();
}
