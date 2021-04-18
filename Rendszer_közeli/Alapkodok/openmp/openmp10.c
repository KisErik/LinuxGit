// Loops in a parallel program 3
// gcc openmp10.c -o openmp10 -fopenmp

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
   int i;
   int ThID;
   int A[4]={0,0,0,0};
   printf("Wait...\n");

   #pragma omp parallel for
//   #pragma omp parallel for schedule(static,1)
//   #pragma omp parallel for schedule(static,4)
//   #pragma omp parallel for schedule(dynamic,1)
//   #pragma omp parallel for schedule(dynamic,4)
//   #pragma omp parallel for schedule(guided)
      for(i=0;i<16;i++){
         ThID = omp_get_thread_num();
         A[ThID]++;
//         printf(" Thread No%d waits %ds.\n",ThID,i==0?5:0);
         if(i==0 || i==6) sleep(5);
         }
   for(i=0;i<4;i++)
      printf("Thread No%d runs %d times.\n",i,A[i]);
   }