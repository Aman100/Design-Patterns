#include<bits/stdc++.h>
using namespace std;
/*
Builder:
It comes under class of Creational Design Pattern;
This pattern is used when object creation is not possible in single line
as we need to build object by specifying lots of properties;

Did Method Chaining in this example to make it Fluent.
*/
class JSONBuilder
{
private:
vector<pair<string,int>> _int;
vector<pair<string,unsigned int>> _uInt;
vector<pair<string,short int>> _shortInt;
vector<pair<string,unsigned short int>> _uShortInt;
vector<pair<string,char>> _char;
vector<pair<string,unsigned char>> _uChar;
vector<pair<string,float>> _float;
vector<pair<string,double>> _double;
vector<pair<string,long double>> _longDouble;
vector<pair<string,long int>> _longInt;
vector<pair<string,unsigned long int>> _uLongInt;
vector<pair<string,long long int>> _longLongInt;
vector<pair<string,unsigned long long int>> _uLongLongInt;
vector<pair<string,string>> _string;

public:
JSONBuilder & add(string key, int val)
{
_int.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, unsigned int val)
{
_uInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, short int val)
{
_shortInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, unsigned short int val)
{
_uShortInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, char val)
{
_char.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, unsigned char val)
{
_uChar.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, float val)
{
_float.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, double val)
{
_double.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, long double val)
{
_longDouble.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, long int val)
{
_longInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, unsigned long int val)
{
_uLongInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, long long int val)
{
_longLongInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, unsigned long long int val)
{
_uLongLongInt.push_back({key,val});
return *this;
}

JSONBuilder & add(string key, string val)
{
_string.push_back({key,val});
return *this;
}

string build()
{
string json="{\r\n";
int x=0;
for(auto p:_int)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_uInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_shortInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_uShortInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_char)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":\"";
json+=p.second;
json+="\"";
x++;
}

for(auto p:_uChar)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":\"";
json+=p.second;
json+="\"";
x++;
}

for(auto p:_float)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_double)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_longDouble)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_longInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_uLongInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_longLongInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_uLongLongInt)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":";
json+=to_string(p.second);
x++;
}

for(auto p:_string)
{
if(x>0) json+=",\r\n";
json+="\t\"";
json+=p.first;
json+="\":\"";
json+=p.second;
json+="\"";
x++;
}
json+="\r\n}";
return json;
}
};

int main()
{
JSONBuilder jsonBuilder;
string jsonString=jsonBuilder.add("int",9119).
add("int",74585).
add("uInt",(unsigned int)123).
add("shortInt",(short int)123).
add("uShortInt",(unsigned short int)456).
add("char",'Z').
add("uChar",(unsigned char)189).
add("float",3.45f).
add("double",9.54).
add("longDouble",418.145416).
add("longInt",(long int)5646464).
add("uLongInt",(unsigned long int)45656464).
add("longLongInt",(long long int)415646).
add("uLongLongInt",(unsigned long long int)9787445416416).
add("string","Hypertech").build();
cout<<jsonString<<endl;
}
