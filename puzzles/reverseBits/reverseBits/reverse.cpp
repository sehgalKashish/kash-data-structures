#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int n;
	printf("\n enter no. :");
	scanf("\n%u", &n);
	cout<<"\n the number is : "<< (bitset<32>) n;
	int result=0;
	int size = sizeof(n)*8;
	for(int i = 0; i < size; i++)
	{
		if(n&1<<i)
		{
			result = result | 1<<(size-i-1);
		}
	}
	cout<<"\n the number is : "<< (bitset<32>) result;
}