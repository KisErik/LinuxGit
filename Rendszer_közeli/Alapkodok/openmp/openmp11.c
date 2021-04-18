// Memory access protection.
// gcc openmp11.c -o openmp11 -fopenmp

#include<stdio.h>
#include<omp.h>

#define N 1000

int main(){
   int i;
   int sum;
   int A[N];

   sum=0;
   for(i=0;i<N;i++)
      A[i]=1;

   #pragma omp parallel for
      for(i=0;i<N;i++){
         #pragma omp critical  // there is influence on result
            sum=sum+A[i];
         }
   printf(" Sum: %d\n",sum);
   }