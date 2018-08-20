#include<iostream>
#include<pthread.h>

using namespace std;

int fact(int n)
{
    if(n== 0 || n==1)
        return n;
    else    
        return n*(n-1);
}


pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c=PTHREAD_COND_INITIALIZER;
int odd=1;

void * printOdd(void *)
{
   
   // pthread_mutex_lock(&m);
     cout<<"In thread printOdd\n";
    // cout<<"odd ="<<odd<<endl;
    // odd+=2;
    // pthread_cond_signal(&c);
    // pthread_mutex_unlock(&m);
}

void *printOddFact(void *)
{
     cout<<"In thread printOddFACT\n";
    // pthread_mutex_lock(&m);
    // pthread_cond_wait(&c,&m);

    // cout<<"fact ="<<fact(odd)<<endl;
    // pthread_mutex_unlock(&m);

}

int main()
{

    pthread_t t1,t2;
    int rc;

    rc=pthread_create(&t1,NULL,printOdd,NULL);
    rc=pthread_create(&t2,NULL,printOddFact,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}