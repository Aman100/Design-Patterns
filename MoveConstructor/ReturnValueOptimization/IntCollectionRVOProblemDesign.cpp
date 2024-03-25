/*
Solution:
Always write our own implementation of Copy, Operator = functions and
do deep copy instead of shallow copy.
*/
#include<bits/stdc++.h>
using namespace std;

class IntCollection
{
private:
int size;
int *ptr;
public:
/*
If programmer doesn't provide constructor in the class then compiler will provide
1. Empty
2. Copy Constructor
If Programmer provide any constructor in the class then compiler will if programmer
provide copy constructor or not, if not provided then compiler will provide
copy constructor.
At every cost copy constructor will be there in the class.

Written by Compiler:
IntCollection (const IntCollection& obj)
{
this->size=obj->size;
this->ptr=obj->ptrl
}

Written By Compiler:
IntCollection & operator=(const IntCollection& obj)
{
this->size=obj.size();
this->ptr=obj.ptr;
return *this; //Return of alias of object return to which this is pointing.
}
*/
IntCollection(unsigned int size)
{
cout<<"Parameterized constructor got called"<<endl;
this->size=size;
this->ptr=new int[this->size];
}
IntCollection(const IntCollection &obj)
{
cout<<"Copy Constructor is invoked"<<endl;
this->size=obj.size;
this->ptr=new int[this->size];
for(int i=0;i<this->size;i++) this->ptr[i]=obj.ptr[i];
}
IntCollection & operator=(const IntCollection &obj)
{
cout<<"operator= function is invoked"<<endl;
this->size=obj.size;
delete [] this->ptr;
this->ptr=new int[this->size];
for(int i=0;i<this->size;i++) this->ptr[i]=obj.ptr[i];
return *this;
}
~IntCollection()
{
cout<<"Destructor got called"<<endl;
delete [] this->ptr;
}
};

IntCollection doSomething()
{
IntCollection intCollection(60);
cout<<"doSomething got called"<<endl;
//code
cout<<"doSomething is about to end"<<endl;
return intCollection;
}

int main()
{
IntCollection f=doSomething(); //Why Copy constructor is not being called.
return 0;
/*
Why Destruction is called only for one object? and for which object destructor
is called?
*/
}