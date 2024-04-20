/*
Singleton pattern: One one object should be created in entire application lifespan.

Problem: From user perspective there will be unnecessary headache of any creating single object. It's the headache of user make sure of creating only single object.
*/

#include<iostream>
using namespace std;

class aaa
{
private:
static int x;
public:
aaa()
{
x++;
if(x>1) throw string("According to Singleton pattern only one object can be created");
}
};
int aaa::x;

int main()
{
try
{
aaa a1;
aaa a2; //headache of remembering of not creating more than one object because of wrong implementation of Singleton pattern
aaa a3;	//headache of remembering of not creating more than one object because of wrong implementation of Singleton pattern
}catch(string &exception)
{
cout<<exception<<endl;
}
}