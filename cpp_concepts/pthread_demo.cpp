#include<iostream>
#include<stdio.h>
#include<pthread.h>

using namespace std;
void *thdFunc(void *arg)
{   
    cout<<"Inside thread x="<<*(int *)arg<<" \n";

    return NULL;
}

int main()
{

    cout<<"main\n";
    pthread_t tid;
    int x=12;
    int rc=pthread_create(&tid,NULL,thdFunc,(void *)&x);
    pthread_join(tid,NULL);
    

    return 0;
}