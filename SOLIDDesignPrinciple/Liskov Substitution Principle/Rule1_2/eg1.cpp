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
virtual void doSomething(int x)
{
if(x<1 || x>2000)	//validating input according to pre condition
{
cout<<"Invalid value of x, it should be in the range of [1,2000]"<<endl;
exit(0);
}
cout<<"Lots of code to process the value of x"<<endl;
cout<<"x is very cool number"<<endl;
}
};

void initiateProcessing(Base &b, int k)
{
b.doSomething(k);
}

int main()
{
int j;
cout<<"Enter data to process: ";
cin>>j;
Base b;
initiateProcessing(b,j);
cout<<"End"<<endl;
return 0;
}
/*
Above code has been written in 2022.
The application has been thoroughly tested according to documentation of the 
base class which states that the agrument related to pre condition should be in
the range of [1,2000].
The application never failed based on the documentation of base class.
*/