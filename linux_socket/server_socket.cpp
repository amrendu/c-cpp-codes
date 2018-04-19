#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<sys/ioctl.h>
#include<unistd.h>

#define SERVER_PATH "/home/amrendu/Desktop/myCodes/IPC/user"
#define BUFFER_LENGTH 250
#define FALSE 0

using namespace std;


int main()
{
    /*Variables */
    int sSocket,cSocket;
    int rc,length;
    char buffer[BUFFER_LENGTH];
    struct sockaddr_un serveraddr;

    /*create server socket */
    sSocket=socket(AF_UNIX,SOCK_STREAM,0);
    if(sSocket<0)
    {
        perror("socket() failed");
        return 0;
    }

    /*bind address to socket*/
      /********************************************************************/
      /* After the socket descriptor is created, a bind() function gets a */
      /* unique name for the socket.                                      */
      /********************************************************************/
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sun_family=AF_UNIX;
    strcpy(serveraddr.sun_path,SERVER_PATH);
    rc=bind(sSocket,(struct sockaddr *)&serveraddr, SUN_LEN(&serveraddr));
    if(rc<0)
    {
        perror("bind () failed");
        return 0;
    }
    
     /********************************************************************/
      /* The listen() function allows the server to accept incoming       */
      /* client connections.  In this example, the backlog is set to 10.  */
      /* This means that the system will queue 10 incoming connection     */
      /* requests before the system starts rejecting the incoming         */
      /* requests.                                                        */
      /********************************************************************/
    rc=listen(sSocket,10);
    if(rc<0)
    {
        perror("listen() failed ");
        return 0;
    }

    printf("Server ready for client connection \n");
     /********************************************************************/
      /* The server uses the accept() function to accept an incoming      */
      /* connection request.  The accept() call will block indefinitely   */
      /* waiting for the incoming connection to arrive.                   */
      /********************************************************************/
    //cSocket=accept(sSocket,)
    while(cSocket=accept(sSocket,NULL,NULL) == -1)
    {
        perror("accept error");
        continue;
    }

    while((rc=read(cSocket,buffer,sizeof(buffer))> 0))
    {
        printf("read %d bytes %s\n",rc,buffer);
    }
    if(rc ==-1)
    {
        perror("read");
        return 0;
    }
    else if (rc== 0)
    {
        printf("EOF\n");
        close(cSocket);
    }
    
    



    return 0;
}
