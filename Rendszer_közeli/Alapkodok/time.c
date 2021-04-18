/*** Example of time treating ***/
#include<stdio.h>
#include<time.h>
#include<unistd.h>

char *Months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char *Days[7]   = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main(){
  time_t act_time1;
  int act_time2, act_time3;
  struct tm *act_time4;
  act_time2 = time(&act_time1);
  printf("The actual time is: %d\n",act_time2);
  printf("This means: %s",ctime(&act_time1));
  act_time4 = localtime(&act_time1);
  printf("So the local time is: %d %s %d  ",(*act_time4).tm_year+1900,Months[(*act_time4).tm_mon],(*act_time4).tm_mday);
  printf("%d:%d:%d\n",(*act_time4).tm_hour,(*act_time4).tm_min,(*act_time4).tm_sec);
  printf(" It is the %dth day of the year.\n",(*act_time4).tm_yday);
  printf(" It is %s.\n",Days[(*act_time4).tm_wday]);
 
  sleep(2);
  usleep(1500000);

  act_time3 = time(&act_time1);
  printf("It took: %ds\n",act_time3-act_time2);
  return 0;
  }
