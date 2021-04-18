/***  Signal sending  ***/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

static int isListen=0;

void listen(int sig){
   isListen=1;
   }

int main(){
   pid_t pid;
   pid=fork();
   if(pid==0){  // child
      printf(" Child: I am working.\n");
      sleep(6); // Child is working
      printf(" Child: I am ready.\n");
      kill(getppid(),SIGUSR1);
      }
   else {  // parent
      printf(" Parent: I am working.\n");
      sleep(3); // Parent is working
      signal(SIGUSR1,listen);
      printf(" Parent: I am waiting for Child's results.\n");
      pause();
      if(isListen==1)
         printf(" Parent: I continue my work.\n");
      else{
         printf(" Parent: I got a signal, but not SIGUSR1.\n");
         return 2;
         }
      sleep(3);
      printf(" The End.\n");
      }
   return 0;
   }
