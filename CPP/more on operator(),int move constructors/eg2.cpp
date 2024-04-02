#include<iostream>
using namespace std;
#define MAX_SIZE 10
class aaa
{
private:
int *ptr;
public:
aaa()
{
cout<<"Default constructor is called"<<'\n'<<'\n';
this->ptr=new int[MAX_SIZE]{20, 30, 40, 50, 60, 70, 80, 90, 100,110};
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=0^this->ptr[i];
}

aaa(const aaa &other)
{
cout<<"Copy constructor is called"<<'\n'<<'\n';
if(this==&other) return;
this->ptr=new int[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=other.ptr[i];
}

aaa(aaa &&other)
{
cout<<"Move constructor is called"<<'\n'<<'\n';
this->ptr=other.ptr;
other.ptr=NULL;
}

void printData()
{
for(int i=0;i<MAX_SIZE;i++) cout<<this->ptr[i]<<" ";
cout<<'\n'<<'\n';
}
};

aaa doSomething()
{
aaa c;
return c; //RVO
}

int main()
{
aaa a;
aaa b(a);
cout<<"Print contents of object a"<<endl;
a.printData();
cout<<"---------------------------"<<'\n'<<'\n';
cout<<"Print contents of object b"<<endl;
b.printData();
aaa d=doSomething();
}