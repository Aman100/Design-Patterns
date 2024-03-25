/*
To make variable p modifiable, declare it will && instead of const int&.
*/
#include<iostream>
using namespace std;
int main()
{
int &&p=50;
cout<<p<<endl;
p=100;
cout<<p<<endl;
}