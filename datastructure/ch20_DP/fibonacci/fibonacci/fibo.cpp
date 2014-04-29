
/*Dynamic programming of fibonacci series*/
#include<iostream>

using namespace std;
#define MAX 3000
int fib(int n);
int arr[MAX];//array to store the result.
void initialise()
{
	for(int i = 0; i < MAX; i++)
		arr[i] = -1;
}
int main()
{
	initialise();
	int n = 0;
	while(n!= -1)
	{
		cout<<"\n enter the term of fibonacci series...<-1 to exit> : ";
		cin>>n;
		cout<<"\ the term is : "<<fib(n);
	}

}
//using top-down approach
/*
int fib(int n)
{
	for(int i = 1; i <= n; i++)
	{
		if(arr[i]<0)
		{
			if(i==1)
				arr[i] = 0;
			else if(i==2)
				arr[i] = 1;
			else 
				arr[i] = fib(n-1)+fib(n-2);
		}
	}
	return arr[n];
}
*/
//bottom up approach
int fib(int n)
{
	for(int i = 1; i <= n; i++)
	{
		if(arr[i]<0)
		{
			if(i==1)
				arr[i] = 0;
			else if(i==2)
				arr[i] = 1;
			else 
				arr[i] = arr[i-1]+arr[i-2];
		}
	}
	return arr[n];
}
