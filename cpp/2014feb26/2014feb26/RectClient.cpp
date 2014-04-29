/* Example to show usage of objects*/

#include"CDummy.h"
#include<iostream>
using namespace std;

int main()
{
	CRectangle c1, c2;		//constructor with out parameters
	CRectangle c3(10,8);	//Parameterized constructor.
	//CRectangle c2;
	c1.set(3, 4);
	c1.Display();
	c2.Display();
	c2(c3);
	c2.Display();
	c3.Display();
}