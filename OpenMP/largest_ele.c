#include<stdio.h>
#include<omp.h>

int main() {
  int numberOfElements, currentMax = -1, iIterator, arrayInput[10000];
  printf("Enter the Number of Elements: ");
  scanf("%d", & numberOfElements);
  for (iIterator = 0; iIterator < numberOfElements; iIterator++) {
    scanf("%d", & arrayInput[iIterator]);
  }
  #pragma omp parallel for reduction(max:currentMax)
  for (iIterator = 0; iIterator < numberOfElements; iIterator++) {
    
    if (arrayInput[iIterator] > currentMax) currentMax = arrayInput[iIterator];
  }
  printf("The Maximum Element is: %d\n", currentMax);
  return 0;
}