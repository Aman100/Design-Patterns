#include<bits/stdc++.h>
using namespace std;

class aaa
{
public:
int operator()(int num1, int num2)
{
return (num1*num2)/__gcd(num1,num2);
}
};

int main()
{
aaa a;
int lcm=a(100,200);
cout<<lcm<<endl;
}