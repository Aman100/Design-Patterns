/*
This is code will not compile as there is no constructor in aaa which accepts
parameter of type bbb;
*/
#include<iostream>
using namespace std;

class aaa
{
int x;
public:
aaa()
{
cout<<"aaa-Default constructor is called"<<endl;
this->x=10;
}
aaa(int x)
{
cout<<"aaa-Parameterized constructor is called"<<endl;
this->x=x;
}
aaa(const aaa &other)
{
cout<<"aaa-Copy constructor is called"<<endl;
this->x=other.x;
}
aaa(aaa &&other)
{
cout<<"aaa-Move constructor is called"<<endl;
this->x=other.x;
other.x=0;
}

void print()
{
cout<<this->x<<endl;
}
};

class bbb
{
public:
bbb()
{
cout<<"bbb-Default constructor is called"<<endl;
}
bbb(const bbb &other)
{
cout<<"bbb-Copy constructor is called"<<endl;
}

operator aaa()
{
//RVO is not applied
aaa d(1000);
return move(d);
}

};

int main()
{
aaa a;
bbb b;
aaa c(b); //This code will compile if b is behaving like an object of aaa type

}