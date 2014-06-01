#include<iostream>
#include<stdio.h>
using namespace std;

class test
{
public:
	test()
	{
		cout<<"\n in constructor.... ";
	}
	test(const test &obj)
	{
		cout<<"\n inside test&obj....";
	}
	void fun()
	{
		cout<<"\n inside fun test....";
	}
};
test func(test obj)
	{
		cout<<"\n inside function func....";
		return obj;
	}
class test2:public test
{
public:
	void fun()
	{
		cout<<"\n inside test2.....";
	}
};
int main()
{
	//test t1, *tr;//result in warning as unreferenced local variable
	//test2 t2;
	//t2.fun();//always call derived clas function
	test t1;
	test t2 = func(t1);
	return 0;

}