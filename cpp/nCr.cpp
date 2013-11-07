#include<iostream>

using namespace std;

int fact(int n);

int main()
{
	long int n,r,result;
	cout<<"enter the value of n and r";
	cin>>n;
	cin>>r;
	if(n<r)
	{
		cout<<"nCr not possible";
		return 1;
	}
	result = fact(n)/(fact(r)*fact(n-r));
	cout<<"the result is :"<<result;
	return 0;
}

int fact(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else if(n == 0)
		return 1;
	else 
		return n*fact(n-1);
}
