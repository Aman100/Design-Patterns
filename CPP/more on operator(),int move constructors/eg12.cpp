#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Default constructor of aaa is called"<<endl;
}
aaa(int x)
{
cout<<"Parameterized constructor of aaa with parameter of int is called"<<endl; 
}
aaa(const aaa& a)
{
cout<<"Copy constructor for aaa is called"<<endl;
}
};


class bbb
{
public:
bbb(aaa a)
{
cout<<"Parameterized constructor of bbb with parameter of aaa is called"<<endl;
}
};

class ccc
{
public:
ccc(bbb a)
{
cout<<"Parameterized constructor of ccc with parameter of bbb is called"<<endl;
}
};

int main()
{
ccc c=bbb{
	aaa{
		10
	 	}
};
}