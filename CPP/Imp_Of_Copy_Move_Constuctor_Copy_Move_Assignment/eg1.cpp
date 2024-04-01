#include<iostream>
using namespace std;

class IntCollection
{
private:
int size;
int *ptr;
public:
int useless;
IntCollection(int size, bool *success)
{
cout<<"Parameterized constructor called"<<endl<<endl;
this->size=size;
if(this->size==0)
{
if(success) *success=true;
this->ptr=NULL;
return;
}
this->ptr=new int[this->size];
if(this->ptr==NULL)
{
if(success) *success=false;
this->size=0;
return;
}
if(success) *success=true;
}

IntCollection(const IntCollection& other)
{
cout<<"Copy constructor is called"<<endl<<endl;
this->size=other.size;
if(this->size==0)
{
this->ptr=NULL;
return;
}
this->ptr=new int[this->size];
if(this->ptr==NULL)
{
this->size=0;
return;
}
for(int i=0;i<this->size;i++) this->ptr[i]=other.ptr[i];
}

IntCollection(IntCollection &&other)
{
cout<<"Move constructor is called"<<endl<<endl;
this->ptr=other.ptr;
this->size=other.size;
other.ptr=NULL;
other.size=0;
}

~IntCollection()
{
delete [] this->ptr;
}

IntCollection & operator=(IntCollection &other)
{
cout<<"Equal To Operator is called"<<endl<<endl;
if(this==&other) return *this;
this->size=other.size;
if(this->size==0)
{
this->ptr=NULL;
return *this;
}
if(this->ptr) delete [] this->ptr;
this->ptr=other.ptr;
for(int i=0;i<this->size;i++) this->ptr[i]=other.ptr[i];
return *this;
}

IntCollection & operator=(IntCollection &&other)
{
cout<<"Move assignment operator= function"<<endl<<endl;
if(this==&other) return *this;
this->size=other.size;
if(this->ptr) delete [] this->ptr;
this->ptr=other.ptr;
other.ptr=NULL;
other.size=0;
return *this;
}

int getSize()
{
return this->size;
}

int & operator[](int index)
{
if(index>=0 && index<this->size) return this->ptr[index];
return this->useless;
}
};

int main()
{
bool status;
IntCollection ic1(10,&status);
if(!status)
{
cout<<"Unable to allocate memory"<<endl;
return 0;
}
cout<<"Size of first collection is : "<<ic1.getSize()<<endl;
ic1[0]=1;
ic1[1]=12;
ic1[2]=13;
ic1[3]=14;
ic1[4]=15;
ic1[5]=16;
ic1[6]=17;
ic1[7]=18;
ic1[8]=19;
ic1[9]=10;
cout<<"Print First Collection"<<endl;
for(int i=0;i<ic1.getSize();i++) cout<<ic1[i]<<" ";
cout<<endl<<endl;
IntCollection ic2(ic1);
cout<<"Size of second collection is : "<<ic2.getSize()<<endl;
cout<<"Print Second Collection"<<endl;
for(int i=0;i<ic2.getSize();i++) cout<<ic2[i]<<" ";
cout<<endl<<endl;
cout<<"Changing size of Collection 2 to check if collection1 & 2 are different"<<endl;
for(int i=0;i<ic2.getSize();i++) ic2[i]=ic2[i]+100;
cout<<"Print First Collection"<<endl;
for(int i=0;i<ic1.getSize();i++) cout<<ic1[i]<<" ";
cout<<endl<<endl;
cout<<"Print Second Collection"<<endl;
for(int i=0;i<ic2.getSize();i++) cout<<ic2[i]<<" ";
IntCollection ic3(static_cast<IntCollection &&>(ic1));
cout<<"Size of first collection is : "<<ic1.getSize()<<endl;
cout<<"Print First Collection"<<endl;
for(int i=0;i<ic1.getSize();i++) cout<<ic1[i]<<" ";
cout<<endl<<endl;
cout<<"Size of third collection is : "<<ic3.getSize()<<endl;
cout<<"Print Third Collection"<<endl;
for(int i=0;i<ic3.getSize();i++) cout<<ic3[i]<<" ";
cout<<endl<<endl;
ic1=ic2;
cout<<"Size of first collection is : "<<ic1.getSize()<<endl;
cout<<"Print First Collection"<<endl;
for(int i=0;i<ic1.getSize();i++) cout<<ic1[i]<<" ";
cout<<endl<<endl;
cout<<"Size of second collection is : "<<ic2.getSize()<<endl;
cout<<"Print Second Collection"<<endl;
for(int i=0;i<ic2.getSize();i++) cout<<ic2[i]<<" ";
cout<<endl<<endl;
IntCollection ic4=static_cast<IntCollection &&>(ic3); //ic4=move(ic3);
cout<<"Size of thrid collection is : "<<ic3.getSize()<<endl;
cout<<"Print third Collection"<<endl;
for(int i=0;i<ic3.getSize();i++) cout<<ic3[i]<<" ";
cout<<endl<<endl;
cout<<"Size of forth collection is : "<<ic4.getSize()<<endl;
cout<<"Print forth Collection"<<endl;
for(int i=0;i<ic4.getSize();i++) cout<<ic4[i]<<" ";
cout<<endl<<endl;
cout<<"Main Ends"<<endl;
return 0;
}
