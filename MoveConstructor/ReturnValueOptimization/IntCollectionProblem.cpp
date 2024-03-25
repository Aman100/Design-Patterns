/*
Problem:
Horrible example because of the way compiler is writing functions. 
(Assigning references of variable)
1. operator = 
2. Copy Constructor
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
~IntCollection()
{
cout<<"Destructor got called"<<endl;
delete [] this->ptr;
}

};

int main()
{
IntCollection a(20);
IntCollection b(25);
IntCollection c(b);
IntCollection d(100);
IntCollection e=40;	//IntCollection e(40)
d=b;
/*
IntCollection c(b);
d=b;

Horrible as memory for member ptr for object b will be released when destructor
is called. Since c is still holding reference of ptr of object b which is destroyed
then when destructor is called for c program will try to release memory for
variable which is already released.
*/

}