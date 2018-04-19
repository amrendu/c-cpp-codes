#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;
#define PORT 8888

/*
Server implementation of network socket */
int main()
{
    int sfd,cfd,rc;
    struct sockaddr_in serv_addr,client_addr;
    /* 1. careate socket */
    sfd= socket(AF_INET,SOCK_STREAM,0);
    if(sfd<0)
    {
        perror("socket syscall failed ");
        return 0;
    }
    cout<<"Socket created with fd : "<<sfd<<endl;

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(PORT);
    /* 2. bind and address to it */
    rc= bind(sfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    if(rc <0)
    {
        perror("bind failed");
        return 0;
    }
    cout<<"Bind success\n";

    /* 3. listen to socket connections */
    rc=listen(sfd,5);
    if(rc <0)
    {
        perror("listen failed ");
        return 0;
    }
    cout<<"Listen success q 5\n";

    socklen_t clientLen=sizeof(client_addr);
    /* accept incoming connections ---> it is blocking call */
    while(1)
    {
        cout<<"waiting for client connection...\n";
        cfd=accept(sfd,(struct sockaddr *)&client_addr,&clientLen);
        if(rc <-1)
        {
            perror("accept failed ");
            return 0;
        }
        else
        {
            cout<<"Connected to client with fd "<<cfd<<endl;
        }
    }

    return 0;
}
