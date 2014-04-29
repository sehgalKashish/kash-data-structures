#include"inherit.h"

Employee::Employee()
{
	id = 0;
	name = "NULL";
	cout<<"\n base class default constructor...";
}
Employee::Employee(int i, string s)
{
	cout<<"\n base class param constructor...";
	id = i;
	name = s;
}
void Employee::setId()
	{
	cout<<"\n enter id";
	cin>>id;
	}
void Employee::setName()
{
	cout<<"\n entr name: ";
	cin >> name;
}
void Employee::getId()
{
	cout<<"id : "<<id;
}
void Employee::getName()
{
	cout<<"\n name : "<<name;
}
void Employee::Display()
{
	cout<<"\n base class display()...";
	cout<<"\n Emp Id: "<<id;
	cout<<"\n Emp name: "<<name;
}
WageEmployee::WageEmployee()
{
	//Employee::Employee();
	hr = 0.0;
	wage = 0;
	cout<<"\n derived class default constructor...";
}
WageEmployee::WageEmployee(int i, string st, float h, int w):Employee(i, st)
{
	//Employee::Employee(i,st);
										/*this will lead to one additional constructor call.
										viz base class default constructor. 
										so use :Employee(i,st) to initalize.*/
	wage = w;
	hr = h;
	cout<<"\n derived class param constructor...";
}
void WageEmployee::Display()
{
	Employee::Display();//do mention the name of the base class
						//else, it will lead to infinite recurrsion.
	
	cout<<"\n time: "<<hr;
	cout<<"\n hourly-wage :"<<wage;
	cout<<"\n derived class display()...";
}
float WageEmployee::salary()
{
	return wage*hr;
}
	