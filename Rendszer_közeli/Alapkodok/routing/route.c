/*** Routing process ***/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<malloc.h>

// Creating a routing table
void init(){
  int fd=open("RT.txt",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR);
  unsigned int *RoutingRow=(unsigned int*)malloc(sizeof(int)*4);

  RoutingRow[0]=(192<<24)|(168<<16)|(0  <<8)|  0;
  RoutingRow[1]=(0  <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[2]=(255<<24)|(255<<16)|(255<<8)|  0;
  RoutingRow[3]=0;
  write(fd,(char*)RoutingRow,sizeof(int)*4);

  RoutingRow[0]=(172<<24)|(16 <<16)|(0  <<8)|  0;
  RoutingRow[1]=(0  <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[2]=(255<<24)|(240<<16)|(0  <<8)|  0;
  RoutingRow[3]=1;
  write(fd,(char*)RoutingRow,sizeof(int)*4);

  RoutingRow[0]=(10 <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[1]=(0  <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[2]=(255<<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[3]=2;
  write(fd,(char*)RoutingRow,sizeof(int)*4);

  RoutingRow[0]=(0  <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[1]=(192<<24)|(168<<16)|(0  <<8)|250;
  RoutingRow[2]=(0  <<24)|(0  <<16)|(0  <<8)|  0;
  RoutingRow[3]=0;
  write(fd,(char*)RoutingRow,sizeof(int)*4);

  close(fd);
  }

// Writing an IP address in dotted-decimal form
void DottedDecimal(unsigned int IPaddress){
  printf("%d.%d.%d.%d",IPaddress>>24,(IPaddress<<8)>>24,(IPaddress<<16)>>24,(IPaddress<<24)>>24);
  }

// Printing a row of the routing table
void printRoutingRow(unsigned int *row){
  DottedDecimal(row[0]);
  printf("\t");
  DottedDecimal(row[1]);
  printf("\t");
  DottedDecimal(row[2]);
  printf("\teth%d\n",row[3]);
  }

// Printing the routing table
void printRoutingTable(){
  int fd;
  unsigned int *RoutingRow;
  int n;
  RoutingRow=(unsigned int*)malloc(sizeof(int)*4);
  fd=open("routing.txt",O_RDONLY);
  if(fd<0){
    fprintf(stderr," Missing config file.\n");
    exit(1);
    }
  do{
    n=read(fd, RoutingRow ,sizeof(int)*4);
    if(n==0) break;
    printRoutingRow(RoutingRow);
    }
  while(1);
  }

// Making the routing process
void RoutingProcess(int IPaddress, unsigned int *Gateway, unsigned int *Interface){
  int fd;
  unsigned int *RoutingRow;
  int n;
  RoutingRow=(unsigned int*)malloc(sizeof(int)*4);
  fd=open("routing.txt",O_RDONLY);
  if(fd<0){
    fprintf(stderr," Missing config file.\n");
    exit(1);
    }
  do{
    n=read(fd, RoutingRow ,sizeof(int)*4);
    if(n==0) break;
    if((IPaddress&RoutingRow[2])==RoutingRow[0]){
      *Gateway=RoutingRow[1];
      *Interface=RoutingRow[3];
      close(fd);
      return;
      }
    }
  while(1);
  close(fd);
  *Gateway = -1;
  }

// Runing: ./route [IP]
int main(int argc, char* argv[]){
  unsigned int Gateway=0, Interface, IPaddress;
  int a1, a2, a3, a4;
  //init();
  if(argc==1) printRoutingTable();
  else {
    sscanf(argv[1],"%d.%d.%d.%d",&a1,&a2,&a3,&a4);
    IPaddress=(a1<<24)|(a2<<16)|(a3<<8)|a4;
    RoutingProcess(IPaddress,&Gateway,&Interface);
    if(Gateway<0) fprintf(stderr, " Not reachable.\n");
    else{
      printf(" Reachable");
      if(Gateway!=0) {
        printf(" through ");
        DottedDecimal(Gateway);
        }
      printf(" via eth%d.\n",Interface);
      }
    }
  return 0;
  }
