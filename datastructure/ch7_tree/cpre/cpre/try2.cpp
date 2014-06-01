#include<iostream>

using namespace std;

int main()
{
	int n;
	cout<<"\n enter the no :";
	cin>>n;
	int size = sizeof(n)*8;
	int result = 0;
	cout<<" the number is : "<< (bitset<32>) n;
	for(int i = 0; i<size; i++)
	{
		if(n&n
		{	
			result = result|