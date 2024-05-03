/*
Composite Pattern: This pattern allows to user to use compositions or Composite
in same way through a common interface.

For user: He is accessing single class but for as a composite pattern implementor
he is wrapping several classes functionalities in a single class.

Scenario: Dheeraj, Nishant, Aman, Shubham created their namespaces in year
2020,2021,2022,2023.
Library has been created for all four developer codes

Goku: Created a interface through which user of interface can access 
functionalities create by Dheeraj, Nishant, Aman, Shubham.

Benefits: User don't need to access all four namespaces separately. 
Goku clubbed all functionalities in single interface. User can use that interface.
*/

#include<bits/stdc++.h>
using namespace std;

//Designed in 2020
namespace Dheeraj
{
class Tablet
{
public:
string getName()
{
return "Tablet Name";
}
string getDescription()
{
return "Tablet Description";
}
string getBrand()
{
return "Tablet Brand";
}
int getPrice()
{
return 25000;
}
};
} //Dheeraj namespace ends

//Designed in 2021
namespace Nishant
{
class Macbook
{
public:
string getName()
{
return "Macbook Name";
}
string getDescription()
{
return "Macbook Description";
}
string getBrand()
{
return "Macbook Brand";
}
int getPrice()
{
return 200000;
}
};
}  //Nishant namespace ends

//Designed in 2022
namespace Aman
{
class Item
{
public:
virtual string getProductName()=0;
virtual string getDetails()=0;
virtual string getCompany()=0;
virtual int getRate()=0;
};

class MobilePhone:public Item
{
private:
string productName;
string details;
string company;
int rate;
public:
MobilePhone(string productName, string details, string company, int rate)
{
this->productName=productName;
this->details=details;
this->company=company;
this->rate=rate;
}
string getProductName()
{
return this->productName;
}
string getDetails()
{
return this->details;
}
string getCompany()
{
return this->company;
}
int getRate()
{
return this->rate;
}
};

class HeadPhone:public Item
{
private:
string productName;
string details;
string company;
int rate;
public:
HeadPhone(string productName, string details, string company, int rate)
{
this->productName=productName;
this->details=details;
this->company=company;
this->rate=rate;
}
string getProductName()
{
return this->productName;
}
string getDetails()
{
return this->details;
}
string getCompany()
{
return this->company;
}
int getRate()
{
return this->rate;
}
};

class Charger:public Item
{
private:
string productName;
string details;
string company;
int rate;
public:
Charger(string productName, string details, string company, int rate)
{
this->productName=productName;
this->details=details;
this->company=company;
this->rate=rate;
}
string getProductName()
{
return this->productName;
}
string getDetails()
{
return this->details;
}
string getCompany()
{
return this->company;
}
int getRate()
{
return this->rate;
}
};

class ProductCatalog
{
private:
array<Item*,5> item;
public:
ProductCatalog()
{
item[0]=new MobilePhone("MobilePhone-1","Phone1-Company","Phone1-Details",20000);
item[1]=new MobilePhone("MobilePhone-2","Phone2-Company","Phone2-Details",70000);
item[2]=new HeadPhone("HeadPhone-1","HeadPhone1-Company","HeadPhone1-Details",2000);
item[3]=new HeadPhone("HeadPhone-2","HEadPhone2-Company","HeadPhone2-Details",3000);
item[4]=new Charger("MobileCharger","MobileCharger-Company","MobileCharger-Details",1100);
}
int getNumberOfItems()
{
return this->item.size();
}
string getProductName(int index)
{
if(index<0 || index>this->item.size()) return "";
return item[index]->getProductName();
}
string getDetails(int index)
{
if(index<0 || index>this->item.size()) return "";
return item[index]->getDetails();
}
string getCompany(int index)
{
if(index<0 || index>this->item.size()) return "";
return item[index]->getCompany();
}
int getRate(int index)
{
if(index<0 || index>this->item.size()) return 0;
return item[index]->getRate();
}
};
}

//Designed in 2023
namespace Shubham
{
class Mixer
{
public:
string getBrand()
{
return "Mixer Brand";
}
string getTitle()
{
return "Mixer Title";
}
string getDescription()
{
return "Mixer Description";
}
int getPrice()
{
return 2000;
}
};

class Oven
{
public:
string getBrand()
{
return "Oven Brand";
}
string getTitle()
{
return "Oven Title";
}
string getDescription()
{
return "Oven Description";
}
int getPrice()
{
return 6250;
}
};

class Stove
{
public:
string getBrand()
{
return "Stove Brand";
}
string getTitle()
{
return "Stove Title";
}
string getDescription()
{
return "Stove Description";
}
int getPrice()
{
return 2000;
}
};

//Another Product Catalog
class Brochure
{
public:
Mixer getMixer()
{
return Mixer();
}
Oven getOven()
{
return Oven();
}
Stove getStove()
{
return Stove();
}
int getItemCount()
{
return 3;
}
};
}

//Composite Pattern Designer
//Designed in 2024
namespace Goku
{
//Wrapper Class
class Product
{
private:
string name;
string description;
string brand;
int price;
public:
Product()
{
this->name="";
this->description="";
this->brand="";
this->price=0;
}
Product(string name, string description, string brand, int price)
{
this->name=name;
this->description=description;
this->brand=brand;
this->price=price;
}
string getName()
{
return this->name;
}
string getDescription()
{
return this->description;
}
string getBrand()
{
return this->brand;
}
int getPrice()
{
return this->price;
}
};

class Catalog
{
private:
Dheeraj::Tablet tablet;
Nishant::Macbook macbook;
Aman::ProductCatalog productCatalog;
Shubham::Brochure brochure;
public:
int getCount()
{
return 2+productCatalog.getNumberOfItems()+brochure.getItemCount();
}
Product operator[](int index)
{
if(index<0 || index>getCount()) return Product();
if(index==0) return Product(tablet.getName(),tablet.getDescription(),tablet.getBrand(),tablet.getPrice());
else if(index==1) return Product(macbook.getName(),macbook.getDescription(),macbook.getBrand(),macbook.getPrice());
else if(index>=2 && index<=productCatalog.getNumberOfItems()+1)
{
return Product(productCatalog.getProductName(index-2),productCatalog.getDetails(index-2),productCatalog.getCompany(index-2),productCatalog.getRate(index-2));
}
else if(index==2+productCatalog.getNumberOfItems())
{
Shubham::Mixer mixer=brochure.getMixer();
return Product(mixer.getBrand(),mixer.getTitle(),mixer.getDescription(),mixer.getPrice());
}
else if(index==3+productCatalog.getNumberOfItems())
{
Shubham::Oven oven=brochure.getOven();
return Product(oven.getBrand(),oven.getTitle(),oven.getDescription(),oven.getPrice());
}
else if(index==4+productCatalog.getNumberOfItems())
{
Shubham::Stove stove=brochure.getStove();
return Product(stove.getBrand(),stove.getTitle(),stove.getDescription(),stove.getPrice());
}
return Product();
}
};
}

using namespace Goku;
int main()
{
Catalog catalog;
for(int i=0;i<catalog.getCount();i++)
{
Product product=catalog[i];
cout<<"ProductName: "<<product.getName()<<"\nProductDescription: "<<product.getDescription()<<"\nProductBrand: "<<product.getBrand()<<"\nProductPrice: "<<product.getPrice()<<endl;
cout<<"-----------------------------------"<<endl;
}
}
