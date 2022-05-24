#include<stdio.h>
#include<omp.h>
int main(){
int i,j,k,m,n,p;
printf("Enter the number of rows in Matrix 1:");
scanf("%d",&m);
int *matrixA[m];
printf("Enter the number of columns in Matrix 1:");
scanf("%d",&n);
for(i=0;i<m;i++){
matrixA[i] = (int *)malloc(n*sizeof(int));
}
printf("<--Now Input the values for matrix 1 row-wise-->\n");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
scanf("%d",&matrixA[i][j]);
}
}
printf("Enter the number of columns in Matrix 2:");
scanf("%d",&p);
int *matrixB[n];
for(i=0;i<n;i++){
matrixB[i] = (int *)malloc(p*sizeof(int));
}
printf("<--Now Input the values for matrix 2 row-wise-->\n");
for(i=0;i<n;i++){
for(j=0;j<p;j++){

    scanf("%d",&matrixB[i][j]);
}
}
int matrixC[m][p];
#pragma omp parallel private(i,j,k) shared(matrixA,matrixB,matrixC)
{
#pragma omp for schedule(static)
for (i=0; i<m; i=i+1){
 for (j=0; j<p; j=j+1){
 matrixC[i][j] = 0;
 for (k=0; k<n; k=k+1){
 matrixC[i][j]=(matrixC[i][j])+((matrixA[i][k])*(matrixB[k][j]));
 }
 }
 }
}
printf("The output after Matrix Multiplication is: \n");
for(i=0;i<m;i++){
for(j=0;j<p;j++)
printf("%d \t",matrixC[i][j]);
printf("\n");
}
return 0;
}