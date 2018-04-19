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
    int sfd,cfd;
    struct sockaddr_in serv_addr,client_addr;
    /* 1. careate socket */
    if( (sfd= socket(AF_INET,SOCK_STREAM,0)	) < 0)
    {
        perror("socket syscall failed ");
        return 0;
    }

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(PORT);
    /* 2. bind and address to it */
    if( bind(sfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        return 0;
    }

    /* 3. listen to socket connections */
    if( listen(sfd,5) <0 )
    {
        perror("listen failed ");
        return 0;
    }

    socklen_t clientLen=sizeof(client_addr);
    /* accept incoming connections ---> it is blocking call */
    if ((accept(cfd,(struct sockaddr *)&client_addr,&clientLen)<0) )
    {
        perror("accept failed ");
        return 0;
    }
    else
    {
        cout<<"Connected to client with fd "<<cfd<<endl;
    }

    





    return 0;
}
