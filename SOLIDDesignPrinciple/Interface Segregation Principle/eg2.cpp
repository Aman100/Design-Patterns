/*
Following class is being written in year 2021 and will be distributed as a
library.

Future programmer wants to get notified everytime wattage or price changes.
To facilitate this the following Bulb class programmer will do.

This example voilates "Interface Segregation" rule because if future programmer
only wants notification regarding price change only or wattage change only then 
it is not possible.
*/
#include<iostream>
using namespace std;

class Bulb;
class StateChangeHandler
{
public:
virtual void priceChanged(int,int,Bulb*)=0;
virtual void wattageChanged(int,int,Bulb*)=0;
};

class Bulb
{
private:
int wattage;
int price;
StateChangeHandler *target;
public:
Bulb()
{
this->wattage=0;
this->price=5;
this->target=NULL;
}
void setWattage(int wattage)
{
if(this->wattage!=wattage)
{
int oldWattage=this->wattage;
this->wattage=wattage;
int newWattage=this->wattage;
if(this->target!=NULL) target->wattageChanged(oldWattage,newWattage,this);
}
}
int getWattage()
{
return this->wattage;
}
void setPrice(int price)
{
if(this->price!=price)
{
int oldPrice=this->price;
this->price=price;
int newPrice=this->price;
if(this->target!=NULL) target->priceChanged(oldPrice,newPrice,this);
}
}
int getPrice()
{
return this->price;
}
void setStateChangeHandler(StateChangeHandler *target)
{
this->target=target;
}
};

/*
Following code is being written in year 2022
*/
class Whatever:public StateChangeHandler
{
public:
Bulb *philips,*bajaj;
Whatever()
{
/*
If programmer doesn't want to get notified about the price state, wattage state
changed then programmer won't require to call setStateChangeHandler.
philips.setStateChangeHandler(this);
*/

/*
If programmer want to get notified about the price state, wattage state
changed then programmer will require to call setStateChangeHandler.
*/
this->philips=new Bulb;
this->bajaj=new Bulb;
philips->setStateChangeHandler(this);
bajaj->setStateChangeHandler(this);
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
void priceChanged(int oldPrice, int newPrice, Bulb* b)
{
if(b==this->philips)
{
cout<<"Philips Bulb's Price change from "<<oldPrice<<" to "<<newPrice<<endl;
}
if(b==this->bajaj)
{
cout<<"Bajaj Bulb's Price change from "<<oldPrice<<" to "<<newPrice<<endl;
}
}
void wattageChanged(int oldWattage, int newWattage, Bulb* b)
{
if(b==this->philips)
{
cout<<"Philips Bulb's Wattage change from "<<oldWattage<<" to "<<newWattage<<endl;
}
if(b==this->bajaj)
{
cout<<"Bajaj Bulb's Wattage change from "<<oldWattage<<" to "<<newWattage<<endl;
}
}
};

int main()
{
Whatever whatever;
cout<<"Whatever instantiated"<<endl;
whatever.doSomething();
}
