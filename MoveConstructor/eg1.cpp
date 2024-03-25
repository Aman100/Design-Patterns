#include<iostream>
using namespace std;

class aaa
{
public:
static int sharedCode;
int allocatedCode;
aaa()
{
sharedCode++;
allocatedCode=sharedCode;
cout<<"Default constructor is invoked with allocatedCode : "<<this->allocatedCode<<endl;
}
aaa(const aaa &obj)
{
sharedCode++;
allocatedCode=sharedCode;
cout<<"Copy constructor is invoked with allocatedCode :"<<this->allocatedCode<<endl;
}
aaa(const aaa &&obj)
{
cout<<"Move constructor is invoked"<<endl;
}
};
int aaa::sharedCode=0;

void doSomething(aaa a)
{
/*
Here a object will not get created and memoryAllocation of anonymous object
will used for object a, so no copy construct will get called.
*/
cout<<"doSomething got called with allocatedCode: "<<a.allocatedCode<<endl;
}

int main()
{
aaa a;
aaa b(a);
doSomething(aaa()); //passing anonymous object
}