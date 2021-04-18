// Getting the number of processors and threads using only one of threads.
// gcc openmp03.c -o openmp03 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){
   int NumThreads;
   int NumProcs;

   NumThreads = omp_get_num_threads();
   NumProcs   = omp_get_num_procs();
   printf("Outside the parallel:\n");
   printf("Number of processors: %d\nNumber of threads: %d\n",NumProcs,NumThreads);

   #pragma omp parallel
      {
      #pragma omp single
        {
        NumThreads = omp_get_num_threads();
        printf("Inside the parallel:\n");
        printf("Number of processors: %d\nNumber of threads: %d\n",NumProcs,NumThreads);
        }
      }
   }