#include<iostream>
using namespace std;
/*
Made RectangleFactory Inner class as Private so no outsider can create object 
of RectangleFactory
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

//FactoryClass
class RectangleFactory
{
public:
Rectangle createRectangleFromSpecificationInCM(int lengthInCM, int breadthInCM)
{
//RVO
return Rectangle(lengthInCM,breadthInCM);
}
Rectangle createRectangleFromSpecificationInFeet(int lengthInFeet, int breadthInFeet)
{
//RVO
return Rectangle(lengthInFeet*30, breadthInFeet*30);
}
};

public:
int getLength()
{
return this->length;
}
int getBreadth()
{
return this->breadth;
}
//One copy of static property is shared by all objects
static RectangleFactory Factory;
};

//Allocating memory for static property
Rectangle::RectangleFactory Rectangle::Factory;

int main()
{
Rectangle r1=Rectangle::Factory.createRectangleFromSpecificationInCM(12,13);
Rectangle r2=Rectangle::Factory.createRectangleFromSpecificationInFeet(5,6);
cout<<r1.getLength()<<", "<<r1.getBreadth()<<endl;
cout<<r2.getLength()<<", "<<r2.getBreadth()<<endl;

//Rectangle::RectangleFactory rr; Invalid as RectangleFactory is private inner class
}