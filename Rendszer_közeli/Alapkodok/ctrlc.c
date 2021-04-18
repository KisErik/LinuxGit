/*** Signal catch ***/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void jajj(int sig){
   printf("\n Jajj!\n");
   signal(SIGINT, SIG_DFL); // back to default signal handling
   }

int main(){
   int i;

   signal(SIGINT, jajj);

   printf("Start...\n");
   for(i=1;i<=10;i++){
      sleep(1);
      printf(" sleeptime: %d s\n",i);
      }
   return 0;
   }
