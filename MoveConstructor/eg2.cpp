#include<bits/stdc++.h>
using namespace std;

class aaa
{
public:
int x=10;
int *ptr;
aaa()
{
this->ptr=new int[2];
ptr[0]=100;
ptr[1]=200;
cout<<"Default constructor is invoked"<<endl;
}
aaa(const aaa &obj)
{
cout<<"Copy constructor is invoked"<<endl;
}
aaa(const aaa &&obj)
{
cout<<"Move constructor is invoked with value of x: "<<obj.x<<endl;
}
void sayHello()
{
cout<<"sayHello"<<endl;
}
};

void doSomething(aaa &a) //reference variable referring to lvalue
{
cout<<"doSomething with aaa& will be called"<<endl;
}

void doSomething(aaa &&a)
{
cout<<"doSomething with aaa&& will be called"<<endl;
}


int main()
{
aaa a;
doSomething(a); 
doSomething(aaa()); //we can try to pass anonymous object to call Move Constructor.

//trying to call move constructor
//aaa b(aaa());
/*
Error: request for member 'sayHello' in 'b', which is of non-class type 
'aaa(aaa (*)())'

anonymous object is getting converted to pointer to a function which will receive
zero parameter and having return type aaa.

When function is having parameter of aaa&& then anonymous object can be passed
but when we try to call Move Constructor then anonymous object is getting converted
to pointer to a function.

b.sayHello();
b=10; //b is a function whose parameter is pointer-to-function and return type is aaa
*/

/*
aaa b(aaa());
compiler will do optimization hence Move constructor will not be called and
memoryAllocation of anonymous object will be assigned to object b*
*/

//Calling Move Constructor
aaa c(static_cast<aaa &&>(a));
cout<<c.x<<" "<<c.ptr[0]<<" "<<c.ptr[1]<<endl;
aaa d(static_cast<aaa &&>(aaa())); //will not be converted to pointer-to-function
}