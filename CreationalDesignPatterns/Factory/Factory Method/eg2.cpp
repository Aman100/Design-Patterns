/*
Solution: Introduce new parameter through which we can specify 
"do we need to treat length,breadth in CM or in FEET"

Problem with this approach:
In documentation we can specify to pass unitOfMeasurement as argument BUT
we would require lot of validation for unitOfMeasurement. Not Good
*/

class Rectangle
{
private:
int lenght;	//In Centimeters
int breadth;	//In Centimeters

Rectangle(int length, int breadth, string unitOfMeasurement)
{	
if(unitOfMeasurement=="CM")
{
this->length=lengthInCM;
this->breadth=breadthInCM;
}
if(unitOfMeasurement=="FEET")
{
this->length=lengthInFeet*30;
this->breadth=breadthInFeet*30;
}
}

};

int main()
{

}