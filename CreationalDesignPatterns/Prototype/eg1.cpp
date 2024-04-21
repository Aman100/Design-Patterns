#include<iostream>
using namespace std;

class City
{
private:
string cityname;
string stdcode;
public:
City(string cityname, string stdcode)
{
this->cityname=cityname;
this->stdcode=stdcode;
}
};

class Degree
{
private:
int years;
public:
Degree(int years)
{
this->years=years;
}
};

class Branch
{
private:
string branchTitle;
public:
Branch(string branchTitle)
{
this->branchTitle=branchTitle;
}
};

class College
{
private:
string collegeTitle;
City &city;
public:
College(string collegeTitle, City &city):collegeTitle(collegeTitle),city(city)
{
}
};

class Student
{
private:
string name;
string dateOfBirth;
Degree &degree;
Branch &branch;
College &college;
City &city;
public:
Student(string name,string dateOfBirth,Degree &degree, Branch &branch,College &college, City &city):name(name),dateOfBirth(dateOfBirth),degree(degree),branch(branch),college(college),city(city)
{

}
};

int main()
{
//We are creating prototypes titled ujjain,indore,btech,
//btech_integrated,cse,ec,MIT,DAVV
City ujjain {"Ujjain","0734"};	//name of the city & STD Code
City indore {"Indore","0731"};	//name of the city & STD Code
Degree btech { 4 };		//number of years
Degree btech_integrated { 5 };	//number of years
Branch cse {"Computer Science & Engineering"};	//Title of branch
Branch ec {"Electronics & Telecommunication"};	//Title of branch
College MIT {"Mahakal Institute Of Technology",ujjain};	//Title Of College & prototype(represents city)
College DAVV {"Devi Ahilya Vishwavidyalaya",indore}; //Title Of College & prototype(represents city)

string name="Aman Warudkar";
string dateOfBirth="09-11-1998";

Student s1 {
name,
dateOfBirth,
btech,
cse,
DAVV,
indore
};

name="Nitesh Kumar";
dateOfBirth="09-06-1992";

Student s2
{
name,
dateOfBirth,
btech_integrated,
ec,
MIT,
ujjain
};

name="Tinker Bell";
dateOfBirth="09-09-1990";
Student s3
{
name,
dateOfBirth,
btech,
cse,
MIT,
ujjain
};
return 0;
}
