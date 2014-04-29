/* swaping numbers using function templates*/
#include<iostream>
using namespace std;

template <class sw>
sw swap(sw x, sw y)
{
	sw temp;
	temp = x;
	x = y;
	y = temp;
	cout<<"\n the value of inta = "<<x<<"value of intb = "<<y;
	
	return 0;
}
int main()
{
	int inta, intb;
	double duba, dubb;
	inta = 4;
	intb = 7;
	duba = 9.4;
	dubb = 9.9;
	swap(inta,intb);
	swap(duba, dubb);
	cout<<"\n the value of inta = "<<inta<<"value of intb = "<<intb;
	cout<<"\n the value of duba = "<<duba<<"value of dubb = "<<dubb;
	return 0;
}