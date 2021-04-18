// Setting the number of threads 1.
// gcc openmp04.c -o openmp04 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){
   printf("Setting the number of threads in compile time by clause.\n");
   #pragma omp parallel num_threads(2)
      {
      printf("I am the thread No%d.\n",omp_get_thread_num());
      }
   }