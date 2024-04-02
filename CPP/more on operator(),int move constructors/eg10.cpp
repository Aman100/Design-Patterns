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
cout<<"Default constructor is called"<<'\n';
this->ptr=new int[MAX_SIZE]{20, 30, 40, 50, 60, 70, 80, 90, 100,110};
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=0^this->ptr[i];
}

aaa(const aaa &other)
{
cout<<"Copy constructor is called"<<'\n';
if(this==&other) return;
if(other.ptr==NULL)
{
this->ptr=NULL;
return;
}
this->ptr=new int[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++) this->ptr[i]=other.ptr[i];
}

aaa(aaa &&other)
{
cout<<"Move constructor is called"<<'\n';
this->ptr=other.ptr;
other.ptr=NULL;
}

void printData()
{
if(this->ptr==NULL)
{
cout<<"Nothing to print"<<endl;
return;
}
for(int i=0;i<MAX_SIZE;i++) cout<<this->ptr[i]<<" ";
cout<<'\n';
}
};

class bbb
{
private:
aaa a;
public:
operator aaa()
{
//RVO will not apply
return move(a);
}
void printData()
{
a.printData();
}
};

int main()
{
bbb b;
aaa g=b; //-> aaa g(b) -> b will behave like aaa type object-> copy constructor
/*
OR
aaa g{b}; 
*/
b.printData();
g.printData();
}