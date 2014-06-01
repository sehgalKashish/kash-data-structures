/*private function “Derived::fun(int )” is being called through
a base class pointer, the program works fine because fun() is 
public in base class. Access specifiers are checked at compile
time and fun() is public in base class. At run time, only the 
function corresponding to the pointed object is called and access
specifier is not checked. So a private function of derived class
is being called through a pointer of base class.
*/

#include<iostream>
using namespace std;

class base
{
public:
	virtual void display()
	{
		cout<<"\n in base::Display()...";
	}
};
class derived: public base
{
private:
	void display()
	{
		cout<<"\n in derived::display()...";
	}
};
int main()
{
	base *ptr;
	derived d;
	//d.display();//error cant access private method of derived.
	ptr = &d;
	ptr->display();

}