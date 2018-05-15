#include<iostream>
#include<stdio.h>

using namespace std;

class myClass
{
    int a,b;

    public:
        myClass(int x,int y){ //constructor
            cout<<"Inside constructor \n";
            a=x;
            b=y;
        } 
        /*
           1) pass by reference because , if not it will be pass by value , 
            which will create copy of object passed --> which will call copy constructor in loop
            
            2)const because logically, it should make no sense to modify an object of which you just want to make a copy, 
        */
        myClass(const myClass &myObj){
            cout<<"Inside copy constructor\n";
            a=myObj.a;
            b=myObj.b;
        }

        int getA(){ return a;}
        int getB(){ return b;}
};

int main()
{
    myClass obj1(10,20);
    cout<<"obj1 A = "<<obj1.getA()<<endl;
    cout<<"obj1 B = "<<obj1.getB()<<endl;

    myClass obj2=obj1;

    cout<<"obj2 A = "<<obj2.getA()<<endl;
    cout<<"obj2 B = "<<obj2.getB()<<endl;

}