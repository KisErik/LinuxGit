/***  Synchronizing by SIGUSR1 signal sending  ***/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

static int isListen=0;

void listen(int sig){
   isListen=1;
   }

void nolisten(){
   isListen=0;
   }

int main(){
   pid_t pid;
   pid=fork();
   if(pid==0){  // child
      printf(" Child: I am working.\n");
      sleep(6); // Child is working
      printf(" Child: I am ready.\n");
      kill(getppid(),SIGUSR1);
      sleep(3); // Child is working
      signal(SIGUSR1,listen);
      printf(" Child: I am waiting for Parent.\n");
      pause();
      if(isListen==1)
         printf(" Child: I continue my work.\n");
      else{
         printf(" Child: I got a signal, but not SIGUSR1.\n");
         return 1;
         }
      sleep(6); // Child is working
      printf(" Child: I am ready.\n");
      }
   else {  // parent
      printf(" Parent: I am working.\n");
      sleep(3); // Parent is working
      signal(SIGUSR1,listen);
      printf(" Parent: I am waiting for Child.\n");
      pause();
      if(isListen==1)
         printf(" Parent: I continue my work.\n");
      else{
         printf(" Parent: I got a signal, but not SIGUSR1.\n");
         return 2;
         }
      nolisten();
      sleep(6);  // Parent is working
      printf(" Parent: I am ready.\n");
      kill(pid, SIGUSR1);
      sleep(3);
      printf(" Parent: I am ready.\n");
      wait(NULL);  // Parent wait for Child end
      printf(" The End.\n");
      }
   return 0;
   }
