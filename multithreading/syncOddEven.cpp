#include<iostream>
#include<stdio.h>
#include<pthread.h>

using namespace std;

volatile int count=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *(printOdd)(void *arg)
{

    do
    {
        pthread_mutex_lock(&lock);
        while(count %2 ==0)
            pthread_cond_wait(&cond,&lock);

        if(count%2!=0)
        {
            cout<<"From Odd :"<<count<<endl;
            count++;
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&lock);
    }while(count<=99);
    pthread_exit(NULL);

}



void *(printEven)(void *arg)
{
    do
    {   
        pthread_mutex_lock(&lock);
        while(count %2 !=0)
            pthread_cond_wait(&cond,&lock);

        if(count%2==0)
        {
            cout<<"From Even :"<<count<<endl;
            count++;
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&lock);

    }while(count<=99);
    cout<<"after loop";
    pthread_exit(NULL);


}



int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,printEven,NULL);
    pthread_create(&t1,NULL,printOdd,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;

}
