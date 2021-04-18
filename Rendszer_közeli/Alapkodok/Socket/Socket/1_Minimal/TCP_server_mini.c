/*****************************************/
/*   - Minimal TCP server for Linux -    */
/*             by Imre Varga             */
/*****************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define BUFSIZE 1024                 // Max length of buffer

int main(){
   /************************** Declarations ********************/
   int sg;                           // socket ID (general)
   int s;                            // socket ID (actual)
   unsigned int client_size;         // length of the sockaddr_in client
   char on=1;                        // sockopt option
   char buffer[BUFSIZE];             // datagram buffer area
   struct sockaddr_in server;        // address of server
   struct sockaddr_in client;        // address of client

   /********************** Initialization **********************/
   server.sin_family      = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port        = htons(2222);

   /********************** Creating socket **********************/
   sg = socket(AF_INET, SOCK_STREAM, 0 );
   setsockopt(sg, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on);
   setsockopt(sg, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof on);

   /************************ Binding socket ***********************/
   bind(sg, (struct sockaddr *) &server, sizeof server);

   /************************ Listening ****************************/
   listen(sg, 10);

   while(1){ // Continuous server operation
      /************************ Accepting connection ****************/
      printf("\n Waiting for connection request...\n");
      s = accept( sg, (struct sockaddr *) &client, &client_size);
      printf(" A client has connected.\n");

      /************************ Receive data *************************/
      printf(" Waiting for a message...\n");
      recv( s, buffer, BUFSIZE, 0 );
      printf (" Client's message:\n  %s", buffer);

      /********************** Sending data *************************/
      sprintf(buffer,"I have received a message.");
      send( s, buffer, strlen(buffer)+1, 0 );
      printf(" Acknowledgement have been sent to client.\n");

      /************************ Closing actual *********************/
      close(s);
      }

   return 0;
   }
