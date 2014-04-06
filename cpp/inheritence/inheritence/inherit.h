#include<iostream>
#include<string>

using namespace std;

class Employee
{
//protected:		//should be declared protected, if they are to be used by derived class.
	int id;
	string name;
public:
	Employee();
	Employee(int i, string s);
	void setId();
	void setName();
	void getId();
	void getName();
	void Display();
};
class WageEmployee:public Employee
{
	float hr;
	int wage;
public:
	WageEmployee();
	WageEmployee(int id, string s, float hr, int wage);
	void Display();
	float salary();
};