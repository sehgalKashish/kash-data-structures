#include"change.h"
int main()
{
	int x;
	int *y;
	y = &x;
	cout<<"\n enter x";
	cin>>(x);
	changeSign(&x);//call by refernce. But function definition's signature doesn't change. magic.. :P

	changeSign(y);//will call to pointer type func. CALL by address
	cout<<"\n afer change x is :"<<x;
}