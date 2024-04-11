/*
Created Factory which will be responsible for creating and delivering object.

Issue: Factory will create object for us but memory will not get released.
Solution: use unique_ptr (Smart Pointer)

Destructor will not get called because Pointer base ka hai unique_ptr mai.
Base k pointer mai derived k object ka address store ho sakta hai but derived 
destructor tb tk nahi chalega jb tb vo base k destructor virtual declare n ho.

Create a wrapper which will contain collection of factory
*/

#include<bits/stdc++.h>
#include<memory>
using namespace std;

class ElectrialsFactory;
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
public:
virtual unique_ptr<Bulb> create(int)=0;
virtual ~BulbFactory(){}
};


class HalogenBulbFactory:public BulbFactory
{
public:
unique_ptr<Bulb> create(int wattage)
{
Bulb* halogenBulb=new HalogenBulb(wattage);
return unique_ptr<Bulb>(halogenBulb);
}
~HalogenBulbFactory()
{
cout<<"HalogenBulbFactory is about to get destroyed"<<endl;
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
~LEDBulbFactory()
{
cout<<"LEDBulbFactory is about to get destroyed"<<endl;
}
};

class ElectricalsFactory
{
private:
unordered_map<string,unique_ptr<BulbFactory>> bulbFactories;
public:
ElectricalsFactory()
{
cout<<"Constructor is called"<<endl;
bulbFactories["Halogen Bulb"]=unique_ptr<BulbFactory>(new HalogenBulbFactory);
bulbFactories["LED Bulb"]=unique_ptr<BulbFactory>(new LEDBulbFactory);
}
unique_ptr<Bulb> createBulb(string type, int wattage)
{
if(bulbFactories[type]) return bulbFactories[type]->create(wattage);
else return unique_ptr<Bulb>(nullptr);
}
};

//Large application Module
void doSomething()
{
ElectricalsFactory electricalsFactory;
unique_ptr<Bulb> halogenBulb=electricalsFactory.createBulb("Halogen Bulb",100);
if(halogenBulb)
{
cout<<"HalogenBulb wattage : "<<halogenBulb->getWattage()<<", Type : "<<halogenBulb->getType()<<endl;
}

auto ledBulb = electricalsFactory.createBulb("LED Bulb",80);
if(ledBulb)
{
cout<<"LEDBulb wattage is : "<<ledBulb->getWattage()<<", Type : "<<ledBulb->getType()<<endl;
}
}

int main()
{
doSomething();
/*
Lot of code over here and doSomething will get called lot of times.
*/

}