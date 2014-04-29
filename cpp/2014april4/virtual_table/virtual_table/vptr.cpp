/*When a class object is created, *__vptr is set to point to the virtual table for that class. 
For example, when a object of type Base is created,
*__vptr is set to point to the virtual table for Base. 
When objects of type D1 or D2 are constructed, 
*__vptr is set to point to the virtual table for D1 or D2 respectively.*/

#include<iostream>

using namespace std;

class base
{
public:
	  virtual void function1()
	{
		cout<<"\n in base func 1.. ";
	}
	void function2()
		{
		cout<<"\n in base func 2.. ";
	}

};

class D1:public base
{
	virtual void function1()
		{
		cout<<"\n in D1 func 1.. ";
	}
};

class D2: public base
{
	void function2()
		{
		cout<<"\n in D2 func 2.. ";
	}
};

int main()
{
	D1 d;
	D2 d2;
	base *ptr;
	ptr = &d;
	ptr->function1();
	ptr = &d2;
	ptr->function2();
}