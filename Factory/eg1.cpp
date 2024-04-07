/*
Need to create object by specifying lengthInCM or lengthInFeet etc..
Constructor parameters will tell clearly because of naming convention that
what type of argument we have to pass.

More functionalities can come but can't follow that approach because 
Parameters of constructor are of same type.
*/

class Rectangle
{
private:
int lenght;	//In Centimeters
int breadth;	//In Centimeters

Rectangle(int lengthInCM, int breadthInCM)
{	
this->length=lengthInCM;
this->breadth=breadthInCM;
}

Rectange(int lengthInFeet, int breadthInFeet)
{
this->length=lengthInFeet*30;
this->breadth=breadthInFeet*30;
}
};

int main()
{

}