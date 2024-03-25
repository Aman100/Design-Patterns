/*
Need to filter out students based on some properties.
We will introduce separate class for that to implement
SingleResponsibilityPrinciple.

Problem: StudentFilter class is open for modification. Lots of requirement
can come and If we keep adding new requirements in StudentFilter then code will
become very messy and less maintainable.
*/

class Student		//Designed in Jan 2018
{
private:
int rollNumber;
string name;
string city;
string institute;
public:
void setRollNumber(int rollNumber)
{
this->rollNumber = rollNumber;
} 
string getRollNumber()
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

//Designed in Jan 2018
class StudentFilter
{
public:

//Requirement Implemented in Jan 2018
vector<Student *> getStudentByInstitute(vector<Student*> &student,string institute)
{
/*
Steps for Logic:
1. Create vector of Student*
2. Iterate sutdent vector and filter Students based filter parameter 
   and insert filtered records into new vector
3. Return new vector
*/
}

//Requirement Implemented in Mar 2018
vector<Student *> getStudentByCity(vector<Student*> &student,string city)
{
/*
Steps for Logic:
1. Create vector of Student*
2. Iterate sutdent vector and filter Students based filter parameter 
   and insert filtered records into new vector
3. Return new vector
*/
}

//Requirement Implemented in April 2018
vector<Student *> getStudentByCityAndInstitute(vector<Student*> &student,string city, string institute)
{
/*
Steps for Logic:
1. Create vector of Student*
2. Iterate sutdent vector and filter Students based filter parameter 
   and insert filtered records into new vector
3. Return new vector
*/
}

//Many more requirements can come in future
};
