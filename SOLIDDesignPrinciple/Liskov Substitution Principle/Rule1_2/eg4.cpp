/*
Parameter of function should be of base type and it should be capable of accepting
derived as an argument but the important part is that the application should not
break.
If on substituting parent with a child then the work should not fail in case of 
child. (Child should be capable to handle tasks in absence of parent)
*/

#include<iostream>
using namespace std;
class Base
{
public:
virtual int doSomething(int x)
{
if(x<1 || x>2000)	//validating input according to pre condition
{
cout<<"Invalid value of x, it should be in the range of [1,2000]"<<endl;
exit(0);
}
cout<<"Lots of code to process the value of x"<<endl;
cout<<"x is very cool number"<<endl;
return x/2; //This operation will tightened post condition, which keep intact LSP
}
};

void initiateProcessing(Base &b, int k)
{
int res=b.doSomething(k);
if(res<1 || res>1000)	//post condition can be tightened but cannot be weakened
{
cout<<"Invalid result, it should be in the range of [1,1000]"<<endl;
exit(0);
}
cout<<"Processing Succeded"<<endl;
}

/*
Above code has been written in year 2022 and it was compiled and library was
created for distribution.

Below code is being written in year 2023
*/

class Derived:public Base
{
/*
Substitution:
Substituting implementation of doSomething(int x); of base class with their own 
implementation in derived class by derived class programmer.

Application will break with pre condition (x<1 || x>100) as the Documentation 
Of base class states that application will work fine if pre condition is 
(x<1 || x>2000) but after writing custom implementation by derived class programmer,
he tightened the pre condition.
If pre condition is weaken it would work fine.
This voilates rule of LSP (Liskov Substitution principle)

Rule: Derived can weaken pre condition but he cannot tightened it.
*/

public:
int doSomething(int x)
{
if(x<1 || x>2000) //kept the pre condition in valid state according to base class condition
{
cout<<"The value of x should be in the range of [1,2000]"<<endl;
exit(0);
}
cout<<"x: "<<x<<" is a super cool number"<<endl;
return x*2;
/*
x*2 will weakned which is opposed to x/2 post condition.

Rule_2: Post condition can be tightened but cannot be weakned.
*/
}
};

int main()
{
Derived d;
int num;
cout<<"Enter input data to process : ";
cin>>num;
initiateProcessing(d,num);
return 0;
}