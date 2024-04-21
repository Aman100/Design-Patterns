/*
Problem: If user release of SingletonMethod object then we are doomed.
*/
#include<bits/stdc++.h>
using namespace std;

class SingletonModel
{
private:
//creating scenario for introducing datastructure in singleton class
list<string> personList;
static SingletonModel *singletonModel;
SingletonModel();
public:
static SingletonModel* getInstance();
list<string> getPersons();
};

SingletonModel * SingletonModel::singletonModel=NULL;

SingletonModel::SingletonModel()
{
cout<<"SingleObject instantiated"<<endl;
//code to populate datastructure
this->personList.push_back("Ramesh");
this->personList.push_back("Suresh");
this->personList.push_back("Nilesh");
this->personList.push_back("Mahesh");
this->personList.push_back("Naresh");
}

SingletonModel * SingletonModel::getInstance()
{
if(singletonModel==NULL) singletonModel=new SingletonModel();
return singletonModel;
}

list<string> SingletonModel::getPersons()
{
return this->personList;
}

int main()
{
SingletonModel *singletonModel1=SingletonModel::getInstance();
for(auto elem:singletonModel1->getPersons()) cout<<elem<<endl;
}