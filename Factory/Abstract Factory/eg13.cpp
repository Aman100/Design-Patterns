/*
Another way of writing init method
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
static int useless;
static unordered_map<string,unique_ptr<BulbFactory>> bulbFactories;
public:
unique_ptr<Bulb> createBulb(string type, int wattage)
{
if(bulbFactories[type]) return bulbFactories[type]->create(wattage);
else return unique_ptr<Bulb>(nullptr);
}
};
unordered_map<string,unique_ptr<BulbFactory>> ElectricalsFactory::bulbFactories;
int ElectricalsFactory::useless=[](){
cout<<"Init method is called"<<endl;
bulbFactories["Halogen Bulb"]=unique_ptr<BulbFactory>(new HalogenBulbFactory);
bulbFactories["LED Bulb"]=unique_ptr<BulbFactory>(new LEDBulbFactory);
return 0;
}();

//Large application Module
void doSomething()
{
ElectricalsFactory electricalsFactory;
//ElectricalsFactory electricalsFactory1; 
//ElectricalsFactory electricalsFactory2;
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

/*
ElectricalsFactory::init(); not possible as init() method is private
*/
doSomething();
/*
Lot of code over here and doSomething will get called lot of times.
*/

}