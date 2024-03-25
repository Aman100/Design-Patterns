/*
Memory has been Released for nameless object using `delete operator` and problem is fixed.
*/

#include<iostream>
using namespace std;

class aaa
{
public:
aaa()
{
cout<<"Default Constructor"<<endl;
}
~aaa()
{
cout<<"Destructor gets called"<<endl;
}
};

void doSomething()
{
aaa *a = new aaa;
cout<<"doSomething gets called"<<endl;

//Doing Stuffs related to object of type aaa
//End doing stuffs

delete a;

//do some other stuffs if needed
}

int main()
{
doSomething();
cout<<"Main Function is about to end"<<endl;
}