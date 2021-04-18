// Private and shared variables.
// gcc openmp07.c -o openmp07 -fopenmp

#include<stdio.h>
#include<omp.h>

int main(){
   int p,s,x;
   int ThreadID;
   p=0;
   s=0;
   x=0;

   printf(" Before the parallel region: p=%d s=%d x=%d\n",p,s,x);
   #pragma omp parallel private(p,ThreadID) shared(s,x)
      {
      p=0;
      ThreadID = omp_get_thread_num();
      x=x+1;
      #pragma omp critical
         {
         p=p+1;
         s=s+1;
         printf(" On thread No%d:              p=%d s=%d x=%d\n",ThreadID,p,s,x);
         }
      }
   printf(" After the parallel region:  p=%d s=%d x=%d\n",p,s,x);
   }
