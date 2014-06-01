/*In C++, if a derived class redefines base class member 
	method then, all the base class methods with sane 
	name become hidden in derived class. 
*/
#include<iostream>
using namespace std;

class base
{
public:
	void fun()
	{
		cout<<"\n in base::fun()...";
	}
	void fun(int a)
	{
		cout<<"\n in base::fun(int i)...";
	}
};
class derived:public base
{
public:
	void fun(int a)
	{
		cout<<"\n in derived::fun()...";
	}
};
int main()
{
	derived d;
	d.base::fun();
	d.fun(5);//will give an ERROR
	//d.fun(
}
/*	Even if the signature of the derived class method is different, 
	all the overloaded methods in base class become hidden. 
	For example, in the following program,Derived::fun(char ) 
	makes both Base::fun() and Base::fun(int ) hidden.
*/