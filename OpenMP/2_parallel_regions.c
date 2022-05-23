#include <omp.h>
#include <stdio.h>
int a, b, i, tid;
float x;
#pragma omp threadprivate(a, x)
int main () {
/* Explicitly turn off dynamic threads */
omp_set_dynamic(0);
printf("1st Parallel Region:\n");
#pragma omp parallel private(b,tid)
 {
tid = omp_get_thread_num();
a = tid;
b = tid;
x = 1.1 * tid +1.0;
printf("Thread %d: a,b,x= %d %d %f\n",tid,a,b,x);
 } /* end of parallel section */
printf("2nd Parallel Region:\n");
#pragma omp parallel private(tid)
 {
tid = omp_get_thread_num();
printf("Thread %d: a,b,x= %d %d %f\n",tid,a,b,x);
 } /* end of parallel section */
}
