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
};


class bbb
{
public:
bbb(aaa a)
{
cout<<"Parameterized constructor of bbb with parameter of aaa is called"<<endl;
}
};
int main()
{
aaa a1;
aaa a2(); /*
This declaration doesn't means that default constructor will be called.
Function can be declared inside a function.
A function whose name is a2 will be called whose parameter is none and return type
is aaa.
*/

aaa a3{}; //For calling default constructor use initializers
bbb b1(a1);
cout<<"1*******************"<<endl;
bbb b2=a1;
cout<<"2*******************"<<endl;
aaa{};	  //An anonymous object of type aaa will be created
cout<<"3*******************"<<endl;
aaa();	  //An anonymous object of type aaa will be created
cout<<"4*******************"<<endl;
bbb b3{a1};
cout<<"5*******************"<<endl;
aaa a4{10};
cout<<"6*******************"<<endl;
bbb{aaa{10}};
cout<<"7*******************"<<endl;
bbb{
	aaa{
		10
	 	}
};
cout<<"8*******************"<<endl;
}