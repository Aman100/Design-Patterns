/*
isPrime will get called and will return 0 or 1 based on input.
isPrime(50)=5000 -> 0=5000 since 1 is an rvalue so this code won't compile

*/

#include<bits/stdc++.h>
using namespace std;
int isPrime(int x)
{
int res=0;
for(int i=2;i*i<=x;i++) if(x%i==0) return res;
return 1;
}
int main()
{
isPrime(50)=5000;
}