/*******************************/
/*       - TCP client -        */
/*        by Imre Varga        */
/*******************************/

#include<stdio.h>
#include<string.h>
#if defined(linux) || defined(_linux) || defined(__linux__) || defined(__unix__) // if Linux
   #define WINDOWS 0
   #include<stdlib.h>
   #include<unistd.h>
   #include<sys/socket.h>
   #include<netinet/in.h>
   #include<arpa/inet.h>
   typedef int WSADATA;
   #define WSAGetLastError() -1
   #define WSAStartup(a,b) 0
   #define closesocket(a) ;
   #define WSACleanup() ;
#else // if Windows
   #define WINDOWS 1
   #include <winsock2.h>
   // Code::Blocks: Settings --> Compiler settings --> Linker settings --> Link libraries: Add: ws2_32
   #pragma comment(lib,"ws2_32.lib") // Winsock Library
   #define close(a) 1
#endif
#define BUFSIZE 1024                 // Max length of buffer
#define PORT_NO 2222                 // The port on which the server is listening

int main(int argc, char *argv[]){    // Server's IPv4 address is needed as command line argument

   /************************** Declarations ********************/
   int s;                            // socket ID
   int flag;                         // transmission flag
   int bytes;                        // received/sent bytes
   int err;                          // error code
   unsigned int server_size;         // length of the sockaddr_in server
   char on;                          // sockopt option
   char buffer[BUFSIZE];             // datagram buffer area
   struct sockaddr_in server;        // address of server

   /********************** Initialization **********************/
   on   = 1;
   flag = 0;
   server.sin_family      = AF_INET;
   server.sin_addr.s_addr = inet_addr(argc==1?"127.0.0.1":argv[1]);
   server.sin_port        = htons(PORT_NO);
   server_size = sizeof server;
   if(WINDOWS){
      static WSADATA wsa;
      if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){ //Initialization of winsock
         fprintf(stderr, " %s: Initialization error (%d).\n", argv[0], WSAGetLastError());
         exit(1);
         }
      }

   /********************** Creating socket **********************/
   s = socket(AF_INET, SOCK_STREAM, 0 );
   if ( s < 0 ) {
      fprintf(stderr, " %s: Socket creation error (%d).\n", argv[0], WSAGetLastError());
      exit(2);
      }
   setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof on);
   setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof on);

   /********************** Connecting ***************************/
   err = connect( s, (struct sockaddr *) &server, server_size);
   if ( err < 0 ) {
      fprintf(stderr, " %s: Connecting error (%d).\n", argv[0], WSAGetLastError());
      exit(3);
      }
   printf(" Connection is OK.\n");

   /********************** Sending data *************************/
   printf(" Message to send: ");
   fgets(buffer,BUFSIZE,stdin);
   bytes = send(s, buffer, strlen(buffer)+1, flag);
   if ( bytes <= 0 ) {
      fprintf(stderr, " %s: Sending error (%d).\n", argv[0], WSAGetLastError());
      exit(4);
      }
   printf (" %i bytes have been sent to server.\n", bytes-1);

   /************************ Receive data *************************/
   bytes = recv(s, buffer, BUFSIZE, flag);
   if ( bytes < 0 ) {
      fprintf(stderr, " %s: Receiving error (%d).\n", argv[0], WSAGetLastError());
      exit(5);
      }
   printf(" Server's (%s:%d) acknowledgement:\n  %s\n",
           inet_ntoa(server.sin_addr), ntohs(server.sin_port), buffer);

   /************************ Closing *****************************/
   if(WINDOWS){
      closesocket(s);
      WSACleanup();
      }
   else
      close(s);

   return EXIT_SUCCESS;
   }
