#include<bits/stdc++.h>
using namespace std;
/*
Another Way of Implementing Solution1
Instead of using Abstract Class we will use PointerToFunction. This approach allow
us to create functions instead of classes.
*/

class Student		//Designed in Jan 2018 and will be distributed in library form
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

//Cannot modify StudentFilter class because this class is following 
//Open Closed Principle
class StudentFilter
{
private:
StudentFilter(){}
public:
static vector<Student*> applyFilter(vector<Student*> &students,
bool (*ptr)(Student*))
{
vector<Student*> studentsV;
for(auto student:students) if(ptr(student)) studentsV.push_back(student);
return studentsV;
}
};

bool ujjainCityFilter(Student *student)
{
return string("Ujjain")==student->getCity();
}

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
vector<Student*> studentVector=StudentFilter::applyFilter(students,ujjainCityFilter);
for(auto student:studentVector)
{
cout<<student->getRollNumber()<<", "<<student->getName()<<", "<<student->getCity()<<", "<<student->getInstitute()<<endl;
}
}