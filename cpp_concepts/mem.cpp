#include<iostream>

using namespace std;

class myclass
{
	int x;
	char *name;
	public:
	myclass(int mx,char *mname)
	{
		x=mx;
		name=mname;
		cout<<"\n constructing "<<name<<" "<<x<<" years\n";
		
	}
};

int main()
{
	char *n="Amrendu";
	myclass *m=new myclass(10,n);
	delete m;
	return 0;
}
