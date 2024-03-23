#include<iostream>
using namespace std;

class aaa
{
public:
void doSomething()
{
cout<<"doSomething gets called"<<endl;
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

//How to call doSomething of aaa class?
b->doSomething();
}

int main()
{
cool();
return 0;
}
