#include<iostream>

using namespace std;

void fun(int);

int main()
{
	int a = 5;
	fun(a);
	fun(a);
	fun(a);
	return 0;
}

void fun(int a)
{
	static int y = a;
	static int z = 1;
	y++;
	z++;
	cout<<" x y z are respectively ..."<<a<<"  "<<y<<"  "<<z<<endl;
}