/*Object slicing happens when a derived class object is assigned
to a base class object, additional attributes of a derived class
object are sliced off to form the base class object.*/

#include<iostream>

using namespace std;

class base
{
protected:
	int i;
public:
	base(int a)
	{
		i = a;
	}
	//virtual void display1() = 0;// another way to prevent slicing. its object cant be instantiated.
	virtual void display()
	{
		cout<<"\n in base class and i = "<<i;
	}
};

class derived:public base
{
	int j;
public: 
	derived(int a, int b):base(a)
	{
		j = b;
	}
	void display()
	{
		cout<<"\n in derived class and i = "<<i<<" j = "<<j;
	}
};
	/*void somefunc(base obj)		//object slicing will take place.
	{
		obj.display();
	}*/

/*	Object slicing doesn’t occur when pointers or 
	references to objectsare passed as function arguments since a 
	pointer or reference of any type takes same amount of memory.
	*/
	void somefunc(base &obj)
	{
		obj.display();
	}
int main()
{
	base b(5);
	derived d(3,4);
	somefunc(b);
	somefunc(d);//object slicing if passed by value, to prevent, pass it by refernce.
}