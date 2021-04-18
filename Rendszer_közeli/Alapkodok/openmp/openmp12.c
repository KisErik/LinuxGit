// Different tasks on each thread
// gcc openmp12.c -o openmp12 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){

   #pragma omp parallel sections
      {
      #pragma omp section
         {
         printf("Section1 %d.\n",omp_get_thread_num());
         }
      #pragma omp section
         {
         printf("Section2 %d.\n",omp_get_thread_num());
         }
      #pragma omp section
         {
         printf("Section3 %d.\n",omp_get_thread_num());
         }
      #pragma omp section
         {
         printf("Section4 %d.\n",omp_get_thread_num());
         }
      }
   }
