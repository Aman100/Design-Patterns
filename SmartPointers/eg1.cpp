/*
When memory is released for local objects Destructor gets called.
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
aaa a;
cout<<"doSomething gets called"<<endl;
}

int main()
{
doSomething();
cout<<"Main Function is about to end"<<endl;
}