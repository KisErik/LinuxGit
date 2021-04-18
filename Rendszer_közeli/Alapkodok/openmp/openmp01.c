// Getting the ID of each thread.
// gcc openmp01.c -o openmp01 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){
   int ThreadID;
   
   #pragma omp parallel
      {
      ThreadID = omp_get_thread_num();
      printf("I am the thread No%d.\n",ThreadID);
      }
   }