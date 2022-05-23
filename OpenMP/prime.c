#include<stdio.h>
#include<omp.h>
int IsPrime(int number)
{
 int i;
 for (i = 2; i < number; i++) {
 if (number % i == 0 && i != number)
 return 0;
 }
 return 1;
}
int main()
{
 int noOfThreads,valueN,indexCount=0,arrayVal[10000],tempValue;
 printf("Enter the Number of threads: ");
 scanf("%d",&noOfThreads);
 printf("Enter the value of N: ");
 scanf("%d",&valueN);
 omp_set_num_threads(noOfThreads);
 #pragma omp parallel for reduction(+:indexCount)
 for(tempValue=2;tempValue<=valueN;tempValue++)
 {
 if(IsPrime(tempValue))
 {
 arrayVal[indexCount] = tempValue; indexCount++;
 }
 }
 printf("Number of prime numbers between 2 and %d : %d\n",valueN,indexCount);
 return 0;
} 
