// Loops in a parallel program 1.
// gcc openmp08.c -o openmp08 -fopenmp

#include<stdio.h>
#include<omp.h>

#define N 16

int main(){
   int i;
   int A[N];
   int ThID;

   // using for in parallel
   #pragma omp parallel num_threads(4) shared(A) private(i,ThID)
      {
      ThID = omp_get_thread_num();
      for(i=ThID*N/4;i<(ThID+1)*N/4;i++){
         A[i] = ThID;
         }
      }
   for(i=0;i<N;i++){
      printf("%d ",A[i]);
      }
   printf("\n");
   }