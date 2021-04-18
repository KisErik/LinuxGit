// Loops in a parallel program 2.
// gcc openmp09.c -o openmp09 -fopenmp

#include<stdio.h>
#include<omp.h>

#define N 16

int main(){
   int i;
   int A[N];

   // using parallel for
   #pragma omp parallel for
      for(i=0;i<N;i++){
         A[i] = omp_get_thread_num();
         }
   for(i=0;i<N;i++){
      printf("%d ",A[i]);
      }
   printf("\n");
   }