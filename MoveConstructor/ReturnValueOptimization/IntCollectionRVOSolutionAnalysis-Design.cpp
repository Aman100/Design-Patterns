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
static int sharedCode;
int allotedCode;
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
sharedCode++;
allotedCode=sharedCode;
this->size=size;
this->ptr=new int[this->size];
cout<<"Parameterized constructor got called for object having alloted code : "<<allotedCode<<" and size : "<<this->size<<endl;
}
IntCollection(const IntCollection &obj)
{
sharedCode++;
allotedCode=sharedCode;
this->size=obj.size;
this->ptr=new int[this->size];
for(int i=0;i<this->size;i++) this->ptr[i]=obj.ptr[i];
cout<<"Copy Constructor is invoked for object having alloted code : "<<allotedCode<<" and size : "<<this->size<<endl;
}
IntCollection & operator=(const IntCollection &obj)
{
cout<<"operator= function is invoked for object which this pointer is referring to is having code : "<<this->allotedCode<<" and size : "<<this->size<<endl;
cout<<"Object which will be copied is having alloted code : "<<obj.allotedCode<<" and size : "<<obj.size<<endl;
this->size=obj.size;
delete [] this->ptr;
this->ptr=new int[this->size];
for(int i=0;i<this->size;i++) this->ptr[i]=obj.ptr[i];
return *this;
}
~IntCollection()
{
cout<<"Destructor got called for object having alloted code : "<<this->allotedCode<<" and size : "<<this->size<<endl;
delete [] this->ptr;
}
};
int IntCollection::sharedCode=0;

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
IntCollection f=doSomething();
cout<<"Main is about to end"<<endl;
/*
After doing analysis we can conclude that destructor is getting called for object
intCollection.
One more thing is happening that Object f is not getting created so copy constructor
is not getting invoked, why?

Answer:
When doSomething() will get called then 2 things happens
1. Copy Constructor will be invoked.
2. Copy Constructor will copy contents of One object to another.

Instead of this what compiler will do is 
1. It will do changes so that intCollection object won't get killed.
2. Object f won't be created and MemoryAllocation for intCollection object 
   will be used for object f. That's the reason why copy constructor didn't got
   called.

This is known as Return Value Optimization (RVO).

We can stop RVO if we make code of doSomething conditional as Compiler won't
evaluate condition. After that object f will be created,copy constructor will get 
called and Destructor will be called for object intCollection, object f.
*/
return 0;
}
