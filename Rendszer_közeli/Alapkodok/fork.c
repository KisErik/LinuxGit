/***  Example of fork  ***/
// gcc -o fork fork.c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
   int x=0;
   pid_t pid;
   fprintf(stdout,"Start...  x=%d\n",x);
   pid=fork();
   if(pid==0){  // Child
      x=1;
      fprintf(stderr,"Child...  x=%d (PID=%d, parent is %d)\n",x,getpid(),getppid());
      sleep(2);  // Child is working...
      fprintf(stderr,"Child ps:\n");
      system("ps -al |grep fork >&2");
      sleep(2);
      fprintf(stderr,"End child. (PID=%d)\n",getpid());
      return 0;
      }
   else{  // Parent
      x=2;
      fprintf(stdout,"Parent... x=%d (PID=%d)\n",x,getpid());
      sleep(6);  // Parent is working...
      fprintf(stdout,"Parent ps:\n");
      system("ps -al |grep fork");
      sleep(2);
      fprintf(stdout,"End parent. (PID=%d)\n",getpid());
      return 0;
      }
   }
