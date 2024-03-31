/*
MODULE1, MODULE2 are there, so objective is to keep those modules loosly coupled.
If in Module2 there is code related to creating a service class which will call
a external service then MODULE1 can't use pointer or object of that service class
otherwise those two modules will be tightly coupled because if new service class
is introduced then programmer need to change the code of MODULE1.
*/
#include<iostream>
using namespace std;

//The above code is being written in year 2021
class FunctionService
{
public:
virtual void send()=0;
};


void someModule(FunctionService *functionService)
{
/*
Code related to place a call to send method through FunctionService pointer
*/
functionService->send();
}


//The below code is being written in year 2021
class AWSFunctionService:public FunctionService
{
public:
void send()
{
cout<<"Connected to AWSPlatform"<<endl;
/*
Code related to connect to AWSPlatform.
*/
}
};

class GoogleCloudFunctionService:public FunctionService
{
public:
void send()
{
/*
Code related to connect to GoogleCloudPlatform.
*/
cout<<"Connected to GoogleCloudPlatform"<<endl;
}
};

int main()
{
//AWSFunctionService *awsFunctionService=new AWSFunctionService();
//someModule(awsFunctionService);
/*
If the requirement changes then the above two lines can be removed and below
two lines can be added, so that only single module will get changed and no change
will be required in "someModule".
*/
GoogleCloudFunctionService *googleCloudFunctionService=new GoogleCloudFunctionService();
someModule(googleCloudFunctionService);
}