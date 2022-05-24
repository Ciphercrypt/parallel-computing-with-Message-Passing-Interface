#include<stdio.h>
#include<omp.h>
int main()
{
int i=0;
int x=0;
#pragma omp parallel shared(i)
{
if(omp_get_thread_num()==0)
{
printf("Master thread with Thread ID:%d\n", omp_get_thread_num());
printf("Since it is the producer thread It is adding some data to be consumed by other consumer threads\n");
i+=10;
x=1;
} else
{
while(x==0)
printf("Waiting for buffer to be filled. Thread ID: %d\n",omp_get_thread_num());
#pragma critical
{
if(i>0){
printf("Data is consumed by Consumer with Thread ID: %d\n",omp_get_thread_num());

i-=5;
} else {
printf("Could not find any data for thread ID: %d\n",omp_get_thread_num());
}}
}
}
}
