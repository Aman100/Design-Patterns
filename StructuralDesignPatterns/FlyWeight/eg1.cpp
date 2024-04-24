/*
FlyWeight Pattern: This pattern is used to reduce memory usage by sharing data
between similar objects. Used in scenario when similar objects are getting created
in large quantity which unnecessary occupy target device's memory.
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
map<int,string*> i2s;
map<string*,int,StringComparator> s2i;
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
unsigned int getKeyFromString(string *str)
{
if(s2i.find(str)==s2i.end()) return 0;
return s2i[str];
}

bool doesStringExistsWRTKey(int key)
{
string *str=i2s[key];
return (i2s.find(key)!=i2s.end());
}

bool doesKeyExistsWRTStr(string *str)
{
return (s2i.find(str)!=s2i.end());
}

static int getLastGeneratedKey()
{
return lastGeneratedKey;
}

};
int StringMap::lastGeneratedKey;

class Student
{
private:
static StringMap stringMap;
int firstNameKey;
int lastNameKey;
public:
void setFirstName(string firstName)
{
int key=stringMap.getKeyFromString(&firstName);
if(key==0) key=stringMap.add(new string(firstName.c_str()));
this->firstNameKey=key;
}
string getFirstName()
{
if(!stringMap.doesStringExistsWRTKey(firstNameKey)) return "";
return string(stringMap.getStringFromKey(firstNameKey)->c_str());
}
void setLastName(string lastName)
{
int key=stringMap.getKeyFromString(&lastName);
if(key==0) key=stringMap.add(new string(lastName.c_str()));
this->lastNameKey=key;
}
string getLastName()
{
if(!stringMap.doesStringExistsWRTKey(lastNameKey)) return "";
return string(stringMap.getStringFromKey(lastNameKey)->c_str());
}
};
StringMap Student::stringMap;

int main()
{
Student s1;
s1.setFirstName("Aman");
s1.setLastName("Warudkar");

Student s2;
s2.setFirstName("Dheeraj");
s2.setLastName("Malviya");

Student s3;
s3.setFirstName("Aman");
s3.setLastName("Warudkar");

Student s4;
s4.setFirstName("Dheeraj");
s4.setLastName("Malviya");

Student s5;
s5.setFirstName("Dheeraj");
s5.setLastName("Malviya");

Student s6;
s6.setFirstName("Nishant");
s6.setLastName("Wagh");

cout<<StringMap::getLastGeneratedKey()<<endl;

cout<<s1.getFirstName()<<" "<<s1.getLastName()<<endl;
cout<<s2.getFirstName()<<" "<<s2.getLastName()<<endl;
cout<<s3.getFirstName()<<" "<<s3.getLastName()<<endl;
cout<<s4.getFirstName()<<" "<<s4.getLastName()<<endl;
cout<<s5.getFirstName()<<" "<<s5.getLastName()<<endl;
cout<<s6.getFirstName()<<" "<<s6.getLastName()<<endl;
}