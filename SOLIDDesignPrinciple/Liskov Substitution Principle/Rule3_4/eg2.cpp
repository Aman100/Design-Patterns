/*
Third, Fourth rules are related to DataType.
*/

#include<bits/stdc++.h>
using namespace std;
class Base
{
public:
long long int powerOfTwo(int num)
{
return 1LL<<num;
}
};

void caller(Base &b, int num)
{
long long int res=b.powerOfTwo(num);
cout<<res<<endl;
}
//Above code written in year 2022.

//Below code is written in year 2023
class Derived:public Base
{
public:
/*
Parameters: While substituting method parameters should be Contravariant.
DataType Size of Parameter variable can be widen.

1. int 				- will work	(Contravariant)
2. long long int 		- will work	(Contravariant)
3. long int 			- will work	(Contravariant)
4. unsigned long long int 	- will work	(Contravariant)
5. short int 			- will not work	(Convariant) --Voilates LPS
6. char				- will not work	(Convariant) --Voilates LPS
7. unsigned char		- will not work	(Convariant) --Voilates LPS

Return Types: While substituting method return type should be Covariant.
Return Type of Substituting method can be tightened.

1. int 				- will work	(Convariant)
2. long long int 		- will work	(Convariant)
3. long int 			- will work	(Convariant)
5. short int 			- will work	(Convariant)
6. char				- will work	(Convariant)
7. unsigned char		- will work	(Convariant)
8. unsigned long long int 	- will not work (Contravariant) --Voilates LPS

*/

unsigned long long int powerOfTwo(short int num)
{
return 1LL<<num;
}
};

int main()
{
Base b;
int num;
cout<<"Enter input data: ";
cin>>num;
caller(b,num);
}
