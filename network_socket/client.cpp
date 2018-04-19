#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
using namespace std;
#define PORT 8888
#define DEST_IP "127.0.0.1"

/*
Client implementation of network socket */

int main()
{
    int cfd;
    struct sockaddr_in client_addr;
    /* 1. careate socket */
    if( (cfd= socket(AF_INET,SOCK_STREAM,0)) < 0)
    {
        perror("socket syscall failed ");
        return 0;
    }

    cout<<"Socket created successfully fd=!!"<<cfd<<endl;
   
    client_addr.sin_family=AF_INET;
    client_addr.sin_addr.s_addr=inet_addr(DEST_IP);
    client_addr.sin_port=htons(PORT);
   
   cout<<"Connecting to server .....\n";

   if(connect(cfd,(struct sockaddr *)&client_addr,sizeof(client_addr)) <0 )
   {
       perror("Connect failed ..:(");
   }

   cout<<"Connected to server .. :)\n";


    return 0;
}