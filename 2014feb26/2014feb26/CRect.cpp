/* C program for function declarations */

#include"CDummy.h"
#include<iostream>

using namespace std;

CRectangle ::CRectangle()
{
	length = 0;
	breadth = 0;
	cout<<"\n Constructor called";
}
CRectangle ::CRectangle(int a, int b)
{
	length = a;
	breadth = b;
	cout<<"\n Param Constructor called";
}
void CRectangle ::set(int a, int b)
{
	length = a;
	breadth = b;
}
void CRectangle ::Display()
{
	cout<<"\n The length is : "<<length;
	cout<<"\n The breadth is :"<<breadth;
}