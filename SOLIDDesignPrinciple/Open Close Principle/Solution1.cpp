#include<bits/stdc++.h>
using namespace std;
/*
OpenClose Principle: It means that the class which was modifiable before
is now open for extension but not modifiable.
*/

class Student		//Designed in Jan 2018
{
private:
int rollNumber;
string name;
string city;
string institute;
public:
Student(int rollNumber, string name, string city, string institute)
{
this->rollNumber=rollNumber;
this->city=city;
this->name=name;
this->institute=institute;
}
void setRollNumber(int rollNumber)
{
this->rollNumber = rollNumber;
} 
int getRollNumber()
{
return this->rollNumber;
}
void setName(string name)
{
this->name = name;
} 
string getName()
{
return this->name;
}
void setCity(string city)
{
this->city = city;
} 
string getCity()
{
return this->city;
}
void setInstitute(string institute)
{
this->institute = institute;
} 
string getInstitute()
{
return this->institute;
}
};

//Create abstract class for imposing guidelines
class StudentFilterSpecification
{
public:
virtual bool accept(Student *)=0;
};


//Cannot modify StudentFilter class because this class is following 
//Open Closed Principle
class StudentFilter
{
private:
StudentFilter(){}
public:
static vector<Student*> applyFilter(vector<Student*> &students,
StudentFilterSpecification *sfs)
{
vector<Student*> studentsV;
for(auto student:students) if(sfs->accept(student)) studentsV.push_back(student);
return studentsV;
}
};

class StudentCityFilter:public StudentFilterSpecification
{
private:
string city;
public:
StudentCityFilter(string city):city(city){}
void setCity(string city)
{
this->city=city;
}
string getCity()
{
return this->city;
}
bool accept(Student *student)
{
return this->getCity()==student->getCity();
}
};

int main()
{
vector<Student *> students;
students.insert(students.end(),{
new Student(1,"Aman","Ujjain","MIT"),
new Student(2,"Amit","Ujjain","GECU"),
new Student(3,"Shubham","Ujjain","SGSITS"),
new Student(4,"Vinay","Ujjain","ALPINE"),
new Student(5,"Praduymn","Indore","DAVV"),
new Student(6,"Dheeraj","Indore","IIM INDORE"),
new Student(7,"Nishant","Indore","SAGE"),
});
vector<Student*> studentVector=StudentFilter::applyFilter(students,new StudentCityFilter("Ujjain"));
for(auto student:studentVector)
{
cout<<student->getRollNumber()<<", "<<student->getName()<<", "<<student->getCity()<<", "<<student->getInstitute()<<endl;
}
}