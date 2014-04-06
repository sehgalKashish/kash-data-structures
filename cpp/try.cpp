#include<iostream>

using namespace std;

int main()
{
	int a, n, b, c;
	cout<<"\nenter no:";
	cin>>n;
	a = n;
	c = 0;
	while(a)
	{
		b = a;
		a =a/10;
		c++;
	}
	int d = b;
	for(int i = 1; i < c; i++)
	{
		d = d*10 + (b+1);
		b = d%10;
	}
	cout<<"sol:"<<d;
}
