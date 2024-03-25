/*
Compiled and we will get output as 3000.
Compiler will do necessary changes.
calculateGcd(10,20)=3000 will be changed to res=3000.
*/
#include<bits/stdc++.h>
using namespace std;
int res;
int & calculateGcd(int x, int y)
{
res=__gcd(x,y);
return res;
}
int main()
{
calculateGcd(10,20)=3000;
cout<<res<<endl;
}