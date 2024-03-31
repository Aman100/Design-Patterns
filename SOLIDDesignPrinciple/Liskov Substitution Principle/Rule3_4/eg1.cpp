/*
Third, Fourth rules are related to DataType.

Below code written in 2022.
Parameter of funtion powerOfTwo, return type of it are compatible. 
LSP rules are intact.
*/

#include<bits/stdc++.h>
using namespace std;
class Base
{
public:
long long int powerOfTwo(short num)
{
return 1LL<<num;
}
};

void caller(Base &b, int num)
{
long long int res=b.powerOfTwo(num);
cout<<res<<endl;
}

int main()
{
//This piece of code was tested thoroughly and it was working fine till year 2022
Base b;
int num;
cout<<"Enter input data: ";
cin>>num;
caller(b,num);
}
