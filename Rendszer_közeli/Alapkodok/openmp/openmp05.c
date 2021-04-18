// Setting the number of threads 2.
// gcc openmp05.c -o openmp05 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){
   int NumProcs;

   NumProcs = omp_get_num_procs();
   omp_set_num_threads((NumProcs==1)?(1):(NumProcs-1));

   printf("Setting number of threads in runtime by function.\n");
   #pragma omp parallel
      {
      printf("I am the thread No%d.\n",omp_get_thread_num());
      }
   }