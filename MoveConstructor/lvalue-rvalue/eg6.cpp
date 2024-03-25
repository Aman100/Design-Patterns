/*
Wrong address of local variable is being returned which will be placed in
place of calculateGcd(10,20).
address=3000
left operand = operator should be a lvalue not rvalue
*/
#include<bits/stdc++.h>
using namespace std;
int res;
int * calculateGcd(int x, int y)
{
res=__gcd(x,y);
return &res;
}
int main()
{
calculateGcd(10,20)=3000;
}