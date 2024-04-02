#include<iostream>
using namespace std;

class aaa
{
public:
operator int()
{
return 911;
}
};

int main()
{
aaa a;
int x=10;
//10+20 = 10 or 20 ka addition nahi hoga instead 10 mai 20 add hoga
int res = x+a;
cout<<res<<endl;
}
