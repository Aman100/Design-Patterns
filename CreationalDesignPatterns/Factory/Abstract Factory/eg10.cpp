#include<iostream>
#include<memory>
using namespace std;
class aaa
{
private:
int x;
public:
aaa()
{
this->x=45456;
}
void printData()
{
cout<<"Data: "<<x<<endl;
}
};

int main()
{
/*
Problem because memory hasn't been allocated to x.
aaa *p=NULL;
p->printData();

Solution:
if(p) p->printData();
*/

/*
Problem: u_ptr is NULL
unique_ptr<aaa> u_ptr(nullptr);
u_ptr->printData();

*/
unique_ptr<aaa> u_ptr(nullptr);
if(u_ptr) u_ptr->printData();

}