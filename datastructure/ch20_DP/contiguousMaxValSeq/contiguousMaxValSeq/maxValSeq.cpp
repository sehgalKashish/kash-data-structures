/**
* Maximum value contigious sequence
**/
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
	//initialize();
	cout<<"\n the max sum is : "<<maxSum(input,6)<<endl;
}
int maxSum(int input[], int n)
{
	table[n] = 0;
	int maxSum = 0;
	if(input[0]>0)
		table[0]=input[0];
	else
		table[0] = 0;
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
	
	/******Doing it in reverse order
	if(input[n-1] > 0)
	{
		table[n-1] = input[n-1];
	}
	else
		table[n-1] = 0;
	for(int i = n-2; i>=0; i--)
	{
		if(table[i+1]+input[i] > 0)
			table[i] = table[i+1]+input[i];
		else
			table[i]=0;
	}
	maxSum = 0;
	for(int i = n-1; i>=0; i--)
	{
		if(table[i]>maxSum)
			maxSum = table[i];
	}
*/
	/******Simple 2 for loop method
	int maxSum = 0;
	for(int i = 0; i < n; i++)
	{
		int sum = 0;
		for(int j = i; j< n; j++)
		{
			sum += input[j];
			if(maxSum < sum )
				maxSum = sum;
		}
		
	}
	********/
	return maxSum;
}
