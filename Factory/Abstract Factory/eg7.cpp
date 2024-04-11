/*
Created Factory which will be responsible for creating and delivering object.

Issue: Factory will create object for us but memory will not get released.
*/
#include<iostream>
using namespace std;

class Bulb
{
public:
virtual void setWattage(int)=0;
virtual int getWattage()=0;
virtual string getType()=0;
};

class HalogenBulb:public Bulb
{
private:
static string type;
int wattage;
HalogenBulb(int wattage)
{
this->wattage=wattage;
}
public:
void setWattage(int wattage)
{
this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
string getType()
{
return "HelogenBulb";
}
~HalogenBulb()
{
cout<<"HalogenBulb desctructor is called"<<endl;
}
friend class HalogenBulbFactory;
};
string HalogenBulb::type="HalogenBulb";

class LEDBulb:public Bulb
{
private:
static string type;
int wattage;
LEDBulb(int wattage)
{
this->wattage=wattage;
}
public:
void setWattage(int wattage)
{
this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
string getType()
{
return "LEDBulb";
}
~LEDBulb()
{
cout<<"LEDBulb descturctor is called"<<endl;
}
friend class LEDBulbFactory;
};
string LEDBulb::type="LEDBulb";

class BulbFactory
{
virtual Bulb * create(int)=0;
};


class HalogenBulbFactory:public BulbFactory
{
public:
Bulb * create(int wattage)
{
Bulb* halogenBulb=new HalogenBulb(wattage);
return halogenBulb;
}
};

class LEDBulbFactory:public BulbFactory
{
public:
Bulb * create(int wattage)
{
Bulb *ledBulb=new LEDBulb(wattage);
return ledBulb;
}
};

//Large application Module
void doSomething()
{
HalogenBulbFactory halogenBulbFactory;
Bulb *halogenBulb=halogenBulbFactory.create(100);
cout<<"HalogenBulb wattage : "<<halogenBulb->getWattage()<<", Type : "<<halogenBulb->getType()<<endl;

LEDBulbFactory ledBulbFactory;
Bulb *ledBulb=ledBulbFactory.create(80);
cout<<"LEDBulb wattage is : "<<ledBulb->getWattage()<<", Type : "<<ledBulb->getType()<<endl;
}

int main()
{
doSomething();
/*
Lot of code over here and doSomething will get called lot of times.
*/

}