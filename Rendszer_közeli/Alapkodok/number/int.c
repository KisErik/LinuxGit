/*** Bitwise operations with integers ***/
#include<stdio.h>

void int2bit(int Num){
  int Digit;
  unsigned int Mask=(1<<((8*sizeof(Num))-1));
  while(Mask!=0){
    Digit=((Num&Mask)==0)?0:1;
    printf("%d",Digit);
    Mask=Mask>>1;
    }
  }

int bit_inc(int N){
  int M=1;
  while(N&M){
    N&=~M;
    M<<=1;
    }
  return M|N;
  }

int bit_add(int A, int B){
  int M=1, r=0, ci=0;
  while(M){
    r|=(((A&M)^(B&M))^ci);
    ci=(((A&M)&(B&M))|(((A&M)^(B&M))&ci))<<1;
    M=M<<1;
    }
  return r;
  }

int bit_signchange(int x){
  return bit_inc(~x);
  }

int bit_sub(int A, int B){
  return bit_add(A,bit_signchange(B));
  }

int main(){
  int x, y;
  printf(" Enter two integers between %d and %d: ",0x80000000,0x7fffffff);
  scanf("%d %d",&x,&y);
  printf("\n  ");
  int2bit(x);
  printf(" (%d)\n -",x);
  int2bit(y);
  printf(" (%d)\n  --------------------------------\n  ",y);
  int2bit(bit_sub(x,y));
  printf(" (%d)\n\n  ",x-y);
  printf("%d - %d = %d\n",x,y,bit_sub(x,y));
  return 0;
  }
