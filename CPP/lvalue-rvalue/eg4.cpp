/*
Wrong as address of local variable is returned
*/
#include<bits/stdc++.h>
using namespace std;
int* calculateGcd(int x, int y)
{
int res=__gcd(x,y);
return &res;
}
int main()
{
int *ptr=calculateGcd(10,20);
}