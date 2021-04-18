// Syncronization.
// gcc openmp06.c -o openmp06 -fopenmp

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
   int i;
   int ThID;
   i=0;

   #pragma omp parallel num_threads(2)
      {
      ThID = omp_get_thread_num();
      if(ThID!=0){
         sleep(1);
         i=1;
         }

      #pragma omp barrier // there is influence on results

      #pragma omp master
         printf(" %d\n",i);
      }
   }