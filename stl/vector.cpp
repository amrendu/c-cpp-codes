#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
int main()
{
    //initializes with 0
    vector<int> a(10);
    cout<<"size= "<<a.size()<<endl; //10
    cout<<"a[9]="<<a[9]<<endl; //0
    cout<<"a[10]="<<a[10]<<endl; //junk or seg fault undefined

    //push_back()  --> appends at the end increase size by 1
    a.push_back(12);
    cout<<"size= "<<a.size()<<endl; //11
    cout<<"a[10] ="<<a[10]<<endl; //12

    //pop_back ---> removes from back decrease size by 1
    a.pop_back();
    cout<<a.size()<<endl;//10

    return 0;
}