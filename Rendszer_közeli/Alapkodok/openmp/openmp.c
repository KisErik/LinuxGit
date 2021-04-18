// Approximation of PI.
// gcc openmp17.c -o openmp17 -fopenmp

#include<stdio.h>

#ifdef _OPENMP
   #include<omp.h>
#else
   #define omp_get_num_procs() 2
#endif

#define N 100000L

int main(){
   unsigned long long x,y;
   unsigned long long r,r2;
   unsigned long long P;
   int NumProcs;

   r2=(unsigned long)N*(unsigned long)N;
   P=0L;
   NumProcs = omp_get_num_procs()-1;
   printf(" Approximation of the value of PI on %d cores.\n",NumProcs);

   #pragma omp parallel for num_threads(NumProcs) private(y) reduction(+:P)
      for(x=0L;x<=N;x++)
         for(y=0L;y<=N;y++)
            if((x*x+y*y)<=r2) P++;

   printf(" PI approximated: %.9lf\n",4.0*(double)P/(double)r2);
   printf(" PI exact:        3.141592653\n");
   }
