/*** Pseudo-random numbers ***/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000

int main(){
  int    i;
  int    x;
  double y;
  int    a[6]={0,0,0,0,0,0};
  int    b[6]={0,0,0,0,0,0};

  srand(time(NULL)); // initialization
  //rand();  // necessary only on Windows

  // integer numbers (int)
  printf(" 0 <= %d <=%d\n",rand(),RAND_MAX);
  printf("20 <= %d <=30\n",rand()%(30-20+1)+20);

  // real number (float)
  printf("0.000000 <= %f <=1.000000\n",(float)rand()/RAND_MAX);
  printf("6.200000 <= %f <=9.800000\n",(float)rand()/RAND_MAX*(9.8-6.2)+6.2);

  // Equal chance
  printf("\nRegular dice (%d throw):\n",N);
  for(i=0;i<N;i++){
    do
      x=rand();
    while(x>=RAND_MAX-RAND_MAX%6);  // To ensure equal probability
    a[x%6]++;
    }
  for(i=0;i<6;i++)
    printf("%d:\t%.4f%%\n",i+1,(float)a[i]/N*100);

  // Not equal chance
  printf("\nTricky dice (%d throw):\n",N);
  for(i=0;i<N;i++){
    y=(double)rand()/((unsigned)RAND_MAX+1); // 0.0 <= y < 1.0
    if(y<0.2) b[0]++;  //20%
    else      b[(int)((y-0.2)/((1.0-0.2)/5))+1]++;
    }
  for(i=0;i<6;i++)
    printf("%d:\t%.4f%%\n",i+1,(float)b[i]/N*100);

  return 0;
  }
