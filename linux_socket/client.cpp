#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<sys/ioctl.h>
#include<unistd.h>
#define SERVER_PATH "/home/amrendu/Desktop/myCodes/IPC/user"


int main()
{
    int fd,rc;
    struct sockaddr_un addr;

    /*creating socket*/
    fd=socket(AF_UNIX,SOCK_STREAM,0);
    if(fd==-1)
    {
        perror("scoket creation failed\n");
        return 0;
    }

    /*init struct */
    memset(&addr,0,sizeof(addr));
    addr.sun_family=AF_UNIX;
    strcpy(addr.sun_path,SERVER_PATH);

    /*connect to socket */
    if(connect(fd,(struct sockaddr*)&addr,sizeof(addr))== 1)
    {
        perror("connect failed \n");
        return 0;
    }
    else
    {
        printf("connected to socket \n");
        char * msg;
        std::cout<<"Enter string to send to server :\n";
        std::cin>>msg;
        write(fd,(const void *)msg,sizeof(msg));

    }




    return 0;
}