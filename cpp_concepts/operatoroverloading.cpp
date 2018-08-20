#include<iostream>
#include<stdio.h>
using namespace std;
class Complex
{
    int r,i;
    public:
    Complex(int r=0, int i=0)
    {
        r=r;
        i=i;
    }

    void print(){ cout<<r<<"+"<<i<<"i"<<endl;}

    Complex operator + (Complex const &obj)
    {
        
    }
};
int main()
{   


    return 0;
}