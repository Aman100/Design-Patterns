/*
Problem:
If multiple threads are going to set some fields in SingletonModel then it would be
bad. How to make it threadsafe?
Do we need to provide setter methods in singleton Object.
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
void operator delete(void *)=delete;
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
SingletonModel *singletonModel=SingletonModel::getInstance();
//delete singletonModel; now this line is useless
for(auto elem:singletonModel->getPersons()) cout<<elem<<endl;

}