/*
Following class is being written in year 2021 and will be distributed as a
library
*/

class Bulb
{
private:
int wattage;
int price;
public:
Bulb()
{
this->wattage=0;
this->price=5;
}
void setWattage(int wattage)
{
if(this->wattage!=wattage) this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
void setPrice(int price)
{
if(this->price!=price) this->price=price;
}
int getPrice()
{
return this->price;
}
};

/*
Following code is being written in year 2022
*/
class Whatever
{
public:
Bulb *philips,*bajaj;
Whatever()
{
this->philips=new Bulb;
this->bajaj=new Bulb;
this->philips->setWattage(10);
this->bajaj->setWattage(15);
this->philips->setPrice(25);
this->bajaj->setPrice(45);
}
void doSomething()
{
this->philips->setWattage(20);
this->bajaj->setWattage(30);
this->philips->setPrice(50);
this->bajaj->setPrice(90);
}
};

int main()
{
Whatever whatever;
whatever.doSomething();
}
