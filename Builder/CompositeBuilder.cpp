/*
When we are required to create an object based on several properties and the
creation of object is based on other objects (composite) then we use composite
builder pattern

Institute:
	Teacher:
	Subjects:
	Address:

Institute:
	properties of teacher:
	properties of subject:
	properties of address:	
	
*/
#include<iostream>
using namespace std;

class InstituteBuilder;
class TeacherBuilder;

class Institute
{
private:
string name;
string instituteName;
string nameOfTeacher;
string specialization;
public:
static InstituteBuilder build();
Institute();
Institute(const Institute &other);
Institute(Institute &&other);
void setName(string);
string getName();
void setInstituteName(string);
string getInstituteName();
void setNameOfTeacher(string);
string getNameOfTeacher();
void setSpecialization(string);
string getSpecialization();
};


class InstituteBuilder
{
public:
Institute institute;
InstituteBuilder();
operator Institute();
InstituteBuilder & name(string);
InstituteBuilder & instituteName(string);
TeacherBuilder teacher();
};

InstituteBuilder Institute::build()
{
//RVO
return InstituteBuilder();
}

Institute::Institute()
{
cout<<"Default constructor Institute is called"<<endl;
}

Institute::Institute(const Institute &other)
{
cout<<"Copy constructor Institute is called "<<endl;
}

Institute::Institute(Institute &&other)
{
cout<<"Move constructor Institute is called"<<endl;
this->setName(other.getName());
this->setInstituteName(other.getInstituteName());
this->setNameOfTeacher(other.getNameOfTeacher());
this->setSpecialization(other.getSpecialization());
other.setName("");
other.setInstituteName("");
other.setNameOfTeacher("");
other.setSpecialization("");
}

void Institute::setName(string name)
{
this->name=name;
}

string Institute::getName()
{
return this->name;
}

void Institute::setInstituteName(string instituteName)
{
this->instituteName=instituteName;
}

string Institute::getInstituteName()
{
return this->instituteName;
}

InstituteBuilder::InstituteBuilder()
{
cout<<"Default constructor of InstituteBuilder is called"<<endl;
}

InstituteBuilder::operator Institute()
{
//RVO will not happen
return move(this->institute);
}

InstituteBuilder& InstituteBuilder::name(string name)
{
this->institute.setName(name);
return *this;
}

InstituteBuilder & InstituteBuilder::instituteName(string instituteName)
{
this->institute.setInstituteName(instituteName);
return *this;
}

void Institute::setNameOfTeacher(string nameOfTeacher)
{
this->nameOfTeacher=nameOfTeacher;
}

string Institute::getNameOfTeacher()
{
return this->nameOfTeacher;
}

void Institute::setSpecialization(string specialization)
{
this->specialization=specialization;
}

string Institute::getSpecialization()
{
return this->specialization;
}

class TeacherBuilder
{
private:
Institute &institute;

public:
TeacherBuilder(Institute &);
TeacherBuilder & name(string);
TeacherBuilder & specialization(string);
operator Institute();
};

TeacherBuilder::TeacherBuilder(Institute &institute):institute{institute}
{
cout<<"Parameterized constructor of TeacherBuilder having parameter of type Institute & is called"<<endl;
}

TeacherBuilder & TeacherBuilder::name(string nameOfTeacher)
{
this->institute.setNameOfTeacher(nameOfTeacher);
return *this;
}

TeacherBuilder & TeacherBuilder::specialization(string specialization)
{
this->institute.setSpecialization(specialization);
return *this;
}

TeacherBuilder::operator Institute()
{
return move(this->institute);
}

TeacherBuilder InstituteBuilder::teacher()
{
return TeacherBuilder(this->institute);
}

int main()
{
//Static method which will return object type of institute builder
Institute institute=Institute::build()
.name("Aman Warudkar")
.instituteName("MIT")
.teacher()
.name("God")
.specialization("Beyond my thinking");

cout<<"Name: "<<institute.getName()<<", Institute Name:"<<institute.getInstituteName()<<endl;
cout<<"Name: "<<institute.getNameOfTeacher()<<", Specialization :"<<institute.getSpecialization()<<endl;
}