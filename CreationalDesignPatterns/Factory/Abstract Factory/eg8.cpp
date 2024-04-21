/*
Created Factory which will be responsible for creating and delivering object.

Issue: Factory will create object for us but memory will not get released.
Solution: use unique_ptr (Smart Pointer)

Destructor will not get called because Pointer base ka hai unique_ptr mai.
Base k pointer mai derived k object ka address store ho sakta hai but derived 
destructor tb tk nahi chalega jb tb vo base k destructor virtual declare n ho.
*/

#include<iostream>
#include<memory>
using namespace std;

class Bulb
{
public:
virtual void setWattage(int)=0;
virtual int getWattage()=0;
virtual string getType()=0;
virtual ~Bulb(){}
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

class BulbFactory	//Abstract Factory
{
virtual unique_ptr<Bulb> create(int)=0;
};


class HalogenBulbFactory:public BulbFactory
{
public:
unique_ptr<Bulb> create(int wattage)
{
Bulb* halogenBulb=new HalogenBulb(wattage);
return unique_ptr<Bulb>(halogenBulb);
}
};

class LEDBulbFactory:public BulbFactory
{
public:
unique_ptr<Bulb> create(int wattage)
{
Bulb *ledBulb=new LEDBulb(wattage);
return unique_ptr<Bulb>(ledBulb);
}
};

//Large application Module
void doSomething()
{
HalogenBulbFactory halogenBulbFactory;
unique_ptr<Bulb> halogenBulb=halogenBulbFactory.create(100);
cout<<"HalogenBulb wattage : "<<halogenBulb->getWattage()<<", Type : "<<halogenBulb->getType()<<endl;

LEDBulbFactory ledBulbFactory;
auto ledBulb = ledBulbFactory.create(80);
cout<<"LEDBulb wattage is : "<<ledBulb->getWattage()<<", Type : "<<ledBulb->getType()<<endl;
}

int main()
{
doSomething();
/*
Lot of code over here and doSomething will get called lot of times.
*/

}