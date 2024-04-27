/*
FlyWeight Pattern for handling large strings.

Requirement:
1. If string size<=2 then store the string as it is in DS and do not generate code.
2. If string size>2 then generate code and store only code in DS and 
    Reference of String along with Code in Map

*/
#include<bits/stdc++.h>
using namespace std;

class StringMap
{
private:
class StringComparator
{
public:
bool operator()(string *left, string *right) const
{
return (*left).compare(*right)<0;
}
};
static int lastGeneratedKey;
unordered_map<unsigned int,string*> i2s;
map<string*,unsigned int,StringComparator> s2i;

public:
unsigned int add(string *str)
{
lastGeneratedKey++;
i2s[lastGeneratedKey]=str;
s2i[str]=lastGeneratedKey;
return lastGeneratedKey;
}

string * getStringFromKey(int key)
{
if(i2s.find(key)==i2s.end()) return NULL;
return i2s[key];
}

int getKeyFromString(string *str)
{
if(s2i.find(str)==s2i.end()) return 0;
return s2i[str];
}

bool doesStringExistsWRTKey(int key)
{
return (i2s.find(key)!=i2s.end());
}

bool doesKeyExistsWRTString(string *str)
{
return (s2i.find(str)!=s2i.end());
}
};
int StringMap::lastGeneratedKey;

class FlyWeightContainer
{
private:
static StringMap stringMap;
string str;
int code;

FlyWeightContainer()
{
}
FlyWeightContainer(string *str=NULL)
{
this->str=(str==NULL)?"":(*str);
this->code=0;
}
FlyWeightContainer(int code=0)
{
this->str="";
this->code=code;
}

public:
static vector<string*> getParsedString(string &p)
{
vector<string*> parsedString;
string tempstr;
int spaceCounter=0;
int commaCounter=0;
int fullStopCounter=0;
for(int i=0;i<p.size();)
{
if(isalpha(p[i])) tempstr+=p[i++];
else
{
/*
For now Symbols are space, comma, fullstop.
More symbols can be added here too.
*/
if(tempstr.size()>0)
{
parsedString.push_back(new string(tempstr.c_str()));
tempstr="";
}
if(i!=p.size())
{
if(p[i]==' ')
{
for(int j=i;j<p.size() && p[i]==' ';j++,i++) spaceCounter++;
tempstr=to_string(spaceCounter)+"s";
spaceCounter=0;
parsedString.push_back(new string(tempstr.c_str()));
}
else if(p[i]==',')
{
for(int j=i;j<p.size()  && p[i]==',';j++,i++) commaCounter++;
tempstr=to_string(commaCounter)+"c";
commaCounter=0;
parsedString.push_back(new string(tempstr.c_str()));
}
else if(p[i]=='.')
{
for(int j=i;j<p.size()  && p[i]=='.';j++,i++) fullStopCounter++;
tempstr=to_string(fullStopCounter)+"f";
fullStopCounter=0;
parsedString.push_back(new string(tempstr.c_str()));
}
tempstr="";
}//If Ends
}//Else Ends
}//ForLoop ends
if(tempstr.size()>0) parsedString.push_back(new string(tempstr.c_str()));
return parsedString;
}

static vector<FlyWeightContainer*> prepareDatastructure(vector<string*> &parsedString)
{
vector<FlyWeightContainer*> fwc;
for(auto str:parsedString)
{
if((*str).size()<=2) fwc.push_back(new FlyWeightContainer(str));
else
{
int code=stringMap.getKeyFromString(str);
if(code==0) code=stringMap.add(str);
fwc.push_back(new FlyWeightContainer(code));
}
}
return fwc;
}

static string getOriginalParagraph(vector<FlyWeightContainer*> &ds)
{
string paragraph;
for(auto fwc:ds)
{
string str=fwc->getStr();
int size=str.size();
if(str.size()==1) paragraph+=str;
else if(str.size()==2) 
{
if(isdigit(str[0]))
{
if(str[1]=='s') for(int i=0;i<str[0]-48;i++) paragraph+=' ';
else if(str[1]=='c') for(int i=0;i<str[0]-48;i++) paragraph+=',';
else if(str[1]=='f') for(int i=0;i<str[0]-48;i++) paragraph+='.';
}
else paragraph+=str;
}
else paragraph+=string(stringMap.getStringFromKey(fwc->getCode())->c_str());
}
return paragraph;
}
string getStr()
{
return this->str;
}
int getCode()
{
return this->code;
}
};
StringMap FlyWeightContainer::stringMap; 

int main()
{
string paragraph="IoT stands for Internet of Things, describing the interconnection of what is usually called smart devices. A smart object is basically any object that is upgraded by technology to provide new capabilities. An electronic chip is usually added to the object to make it smart, enabling it to interact, process data and communicate. These are the main characteristics of the intelligence of things. The interaction firstly consists of collecting data about the direct environment of the object. These data are processed and possibly spread, and the processing eventually leads to a second interaction, the object acting according to the previous steps. The ability to sense, analyze, decide and react constitutes the core of smart devices. Such smart devices can be used in many domains, and do not necessarily require any networking to work. Recent improvements in technologies, such as miniaturization and consumption reduction, helped to spread the use of these devices. In the ultra connected world we live in, these objectswere given the faculty to communicate with each other, thus creating the Internet of Things. The IoT, as its name suggests, looks alike the world wide Internet. It consists of the interconnection of huge amounts of smart devices that communicate and exchange data. Just as the Internet, it is a best effort network that organizes itself so that any device can be added or removed. The network is commonly structured following this architecture";

vector<string*> parsedString=FlyWeightContainer::getParsedString(paragraph);
vector<FlyWeightContainer*> ds=FlyWeightContainer::prepareDatastructure(parsedString);
string str=FlyWeightContainer::getOriginalParagraph(ds);
cout<<endl<<"STRING: "<<str<<endl;
}
