/*
Implementation of Trick (so called smart pointer)
*/

#include<iostream>
#include<memory>
using namespace std;

class aaa
{
private:
int id;
public:
void setId(int id)
{
this->id=id;
}
int getId()
{
return this->id;
}
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
unique_ptr<aaa> smartPtr(new aaa), sptr2;
sptr2=smartPtr;
smartPtr->setId(101);
cout<<"Id is "<<smartPtr->getId()<<endl;
cout<<"doSomething gets called"<<endl;
}

int main()
{
doSomething();
cout<<"Main Function is about to end"<<endl;
}