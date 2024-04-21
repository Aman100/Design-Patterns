#include<iostream>
using namespace std;
/*
Instead of creating factory methods we can bundle those method in separate class.
It will be named as FactoryClass.
*/

class RectangleFactory;
class Rectangle
{
private:
int length;	//In Centimeters
int breadth;	//In Centimeters
Rectangle(int length, int breadth)
{
this->length=length;
this->breadth=breadth;
}
public:
int getLength()
{
return this->length;
}
int getBreadth()
{
return this->breadth;
}

/*
OOP Perspective: friend keyword with classname is used to relate two non 
related entities.
*/
friend RectangleFactory;
};

//FactoryClass
class RectangleFactory
{
private:
RectangleFactory(){}
public:
static Rectangle createRectangleFromSpecificationInCM(int lengthInCM, int breadthInCM)
{
//RVO
return Rectangle(lengthInCM,breadthInCM);
}
static Rectangle createRectangleFromSpecificationInFeet(int lengthInFeet, int breadthInFeet)
{
//RVO
return Rectangle(lengthInFeet*30, breadthInFeet*30);
}
};

int main()
{
Rectangle r1=RectangleFactory::createRectangleFromSpecificationInCM(12,13);
Rectangle r2=RectangleFactory::createRectangleFromSpecificationInFeet(5,6);
cout<<r1.getLength()<<", "<<r1.getBreadth()<<endl;
cout<<r2.getLength()<<", "<<r2.getBreadth()<<endl;
}