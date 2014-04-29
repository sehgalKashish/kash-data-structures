#include"change.h"

int changeSign(int x)
{
	cout<<"\n in simple...";
	if(x)
		x = -x;
	cout<<"\n simple: "<<x;
	return 0;
}
int changeSign(int *x)
{
	cout<<"\n in pointer type.. ";
	if(*x)
		*x = -(*x);
	cout<<"\n pointer: "<<*x;
	return 0;
}
