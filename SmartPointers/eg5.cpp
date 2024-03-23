/*
Idea of Smart Pointers
*/
#include<iostream>
using namespace std;

class aaa
{
public:
aaa()
{
cout<<"Default Constructor gets called"<<endl;
}
void doSomething()
{
cout<<"doSomething gets called"<<endl;
}
~aaa()
{
cout<<"Destructor gets called"<<endl;
}
};

class bbb
{
private:
aaa *ptr;
public:

bbb(aaa *a)
{
this->ptr=a;
}
~bbb()
{
delete this->ptr;
}
aaa* operator-> ()
{
return this->ptr;
}
};

void cool()
{
aaa *a;
a=new aaa;
bbb b(a);
b->doSomething();
}

int main()
{
cool();
return 0;
}
