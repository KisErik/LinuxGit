// Tasks only for master.
// gcc openmp02.c -o openmp02 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){

   #pragma omp parallel
      {
      #pragma omp master
        {
        printf("I am the master.\n");
        }
      }
   }