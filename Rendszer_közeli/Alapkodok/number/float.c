/*** Bitwise operations with floats ***/
#include<stdio.h>
union var{
   int i;
   float f;
   };

void write_bin(float a){
   int size=8*sizeof(a);
   int i,d;
   union var aa;
   aa.f=a;
   unsigned int mask=(1<<(size-1));
   for(i=1;i<=size;i++){
      d=((aa.i&mask)==0)?0:1;
      printf("%d",d);
      if(i%8==0) printf(" ");
      mask=mask>>1;
      }
   }

float power(float b, int e){
   if(e<0){
      e*=-1;
      b=1/b;
      }
   float p=1;
   for(;e>0;e--)
      p*=b;
   return p;
   }
void write_dec(float a){
   int *aa;
   int size=8*sizeof(a);
   int i,j,d;
   int S,K=0;
   double M=0;
   unsigned int mask=(1<<(size-1));
   aa=(int*)&a;
   for(i=1;i<=size;i++){
      if(((*aa)&mask)==0) d=0;
      else d=1;
      if(i==1) S=d;
      if(i>=2 && i<=9){
         j=i-1;
         K+=d*power(2,8-j);
         }
      if(i>=10){
         j=i-9;
         M+=d*power(0.5,j);
         }
      mask=mask>>1;
      }
   K-=127;
   printf("%.10f",power(-1,S)*power(2,K)*(1+M));
   }

int main(){
   float x=2.5;
//   float x=-2.5;
   printf("%f\n",x);
   printf("%.10f\n",x);
   write_dec(x);
   printf("\n");
   write_bin(x);
   printf("\n");
   return 0;
   }
