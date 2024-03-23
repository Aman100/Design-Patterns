/*
When memory is allocated for nameless objects then Destructor will not gets
invoked which used to happened incase of named objects.

Memory has to be explictly relesed for nameless objects.
When memory is not released for nameless objects then it will occupy space.
Technically it is called as MemoryLeak.
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
}

int main()
{
doSomething();
cout<<"Main Function is about to end"<<endl;
}