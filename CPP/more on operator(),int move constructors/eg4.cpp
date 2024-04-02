#include<iostream>
using namespace std;
#define MAX_SIZE 10
class aaa
{
private:
int *ptr;
int code;
static int allocatedCode;
public:
aaa()
{
allocatedCode++;
code=allocatedCode;
cout<<"Default constructor is called with code : "<<code<<'\n';
this->ptr=new int[MAX_SIZE]{20, 30, 40, 50, 60, 70, 80, 90, 100,110};
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=0^this->ptr[i];
}

aaa(const aaa &other)
{
allocatedCode++;
code=allocatedCode;
cout<<"Copy constructor is called with code : "<<code<<'\n';
if(this==&other) return;
this->ptr=new int[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=other.ptr[i];
}

aaa(aaa &&other)
{
allocatedCode++;
code=allocatedCode;
cout<<"Move constructor is called with code : "<<code<<'\n';
this->ptr=other.ptr;
other.ptr=NULL;
}

void printData()
{
for(int i=0;i<MAX_SIZE;i++) cout<<this->ptr[i]<<" ";
cout<<'\n'<<'\n';
}

~aaa()
{
cout<<"Destructor is called with code : "<<this->code<<'\n';
delete [] this->ptr;
}

};
int aaa::allocatedCode=0;

aaa doSomething()
{
aaa c;
return move(c);
}

int main()
{
aaa a;
aaa b(a);
cout<<"Print contents of object a"<<endl;
a.printData();
cout<<"---------------------------"<<'\n';
cout<<"Print contents of object b"<<endl;
b.printData();
aaa d=doSomething();
cout<<"---------------------------"<<'\n';
cout<<"Print contents of object d (moved from object c)"<<endl;
b.printData();
}