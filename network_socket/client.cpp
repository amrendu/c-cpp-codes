#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<pthread.h>
#define PORT 8888
#define DEST_IP "127.0.0.1"
#define BUFF_SIZE 512
void startConvo(int fd);

using namespace std;
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

    cout<<"Socket created successfully fd= "<<cfd<<endl;
   
    client_addr.sin_family=AF_INET;
    client_addr.sin_addr.s_addr=inet_addr(DEST_IP);
    client_addr.sin_port=htons(PORT);
   
   cout<<"Connecting to server .....\n";

   if(connect(cfd,(struct sockaddr *)&client_addr,sizeof(client_addr)) <0 )
   {
       perror("Connect failed ..:(");
   }
    else
    {
        cout<<"Connected to server .. :)\n";
        startConvo(cfd);


    }


    return 0;
}

void * rcvThread(void *fd)
{
    char rcvbuff[BUFF_SIZE];
    int *fd1=(int *)fd;
    while (1)
    {
        recv(*fd1,rcvbuff,BUFF_SIZE,0);
        cout<<"FROM SERVER :"<<rcvbuff<<endl;
    }
}

void startConvo(int fd)
{
    cout<<"Convo started... \n";
    pthread_t tid;
    pthread_create(&tid,NULL,rcvThread,(void *)&fd);
    while(1)
    {
        
        char sendbuff[BUFF_SIZE];
        cin>>sendbuff;
        send(fd,sendbuff,BUFF_SIZE,0);
        //cout<<"ME :"<<sendbuff<<endl;
       
    }

}