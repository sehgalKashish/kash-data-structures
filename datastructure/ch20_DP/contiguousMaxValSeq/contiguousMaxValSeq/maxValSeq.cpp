#include<iostream>

using namespace std;
#define MAX 100
int table[50];
void initialize()
{
	for(int i = 0; i<50; i++)
		table[i] = 0;
}

int maxSum(int input[], int n);
int main()
{
	int input[] = {-2, 11, -4, 13, -5, 2};
	//initialise();
	cout<<"\n the max sum is : "<<maxSum(input,6);
}
int maxSum(int input[], int n)
{
	table[n] = 0;
	int maxSum = 0;
	if(input[0]>0)
		table[0]=input[0];
	else
		table[0] = input[0];
	for(int i = 1; i<n; i++)
	{
		if(table[i-1]+input[i]>0)
			table[i] = table[i-1]+input[i];
		else
			table[i] = 0;
	}
	maxSum = 0;
	for(int i = 1; i<n; i++)
	{
		if(table[i]>maxSum)
			maxSum = table[i];
	}
	return maxSum;
}
