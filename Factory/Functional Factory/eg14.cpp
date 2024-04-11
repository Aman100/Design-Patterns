/*
Functional Factory.
We put function against Map instead of object hence it's an example of functional
factory. 
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
friend class ElectricalsFactory;
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
friend class ElectricalsFactory;
};
string LEDBulb::type="LEDBulb";

class ElectricalsFactory
{
private:
static int useless;
static unordered_map<string,unique_ptr<Bulb>(*)(int)> bulbFactories;
public:
static unique_ptr<Bulb> createBulb(string type, int wattage)
{
if(bulbFactories[type]) return bulbFactories[type](wattage);
else return unique_ptr<Bulb>(nullptr);
}
};
unordered_map<string,unique_ptr<Bulb>(*)(int)> ElectricalsFactory::bulbFactories;
int ElectricalsFactory::useless=[](){
bulbFactories["Halogen Bulb"]=[](int wattage){
return unique_ptr<Bulb>(new HalogenBulb(wattage));
};
bulbFactories["LED Bulb"]=[](int wattage){
return unique_ptr<Bulb>(new LEDBulb(wattage));
};
return 0;
}();

//Large application Module
void doSomething()
{
unique_ptr<Bulb> halogenBulb=ElectricalsFactory::createBulb("Halogen Bulb",100);
if(halogenBulb)
{
cout<<"HalogenBulb wattage : "<<halogenBulb->getWattage()<<", Type : "<<halogenBulb->getType()<<endl;
}

auto ledBulb = ElectricalsFactory::createBulb("LED Bulb",80);
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