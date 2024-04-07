/*
Solution:
Create separate method as per requirements. Those methods will be responsible
for object creation is arguments are valid.

Achieve clean and readable code
*/

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
static Rectangle fromSpecificationInCM(int lengthInCM, int breadthInCM)
{
return Rectangle(lengthInCM,breadthInCM);
}
static Rectangle fromSpecificationInFeet(int lengthInFeet, int breadthInFeet)
{
return Rectangle(lengthInFeet*30, breadthInFeet*30);
}
};

int main()
{
// Rectange(10,20) not accessible
Rectangle r1=Rectangle::fromSpecificationInCM(12,13);
Rectangle r2=Rectangle::fromSpecificationInFeet(5,6);
/*
These are factory methods responsible for creating and delivering Rectangle.
fromSpecificationInCM(12,13);
fromSpecificationInFeet(5,6);

*/
}