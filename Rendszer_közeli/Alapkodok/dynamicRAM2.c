/*** Example of arbitrary size array with dynamic memory allocation ***/
#include<stdio.h>
#include<malloc.h>

float average(int *A, int N){
  int i, sum=0;
  for(i=0;i<N;i++)
    sum+=A[i];
  return (float)sum/N;
  }

int main(){
  int i=-1;
  int Size=1;
  int *D;

  printf(" Give integers until 0.\n");
  D = (int*)malloc(sizeof(int));
  do{
    i++;
    if(i==Size){
      Size*=2;
      D=(int*)realloc(D,sizeof(int)*Size);
    }
    printf("  No %d: ",i+1);
    scanf("%d",&D[i]);
    }
  while(D[i]!=0);
  Size=i;
  D=(int*)realloc(D,sizeof(int)*Size);

  printf(" Average of all number: %f\n",average(D,Size));
  printf(" Average of the second half: %f\n",average(&D[Size/4],Size/2));

  return 0;
  }
