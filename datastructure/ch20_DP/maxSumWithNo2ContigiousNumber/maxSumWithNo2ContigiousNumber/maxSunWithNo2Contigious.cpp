/**
* Find the sum of elements in the subsequence, here the condition is that we should 
* not select 2 contigious numbers.
**/

#include<iostream>

using namespace std;

int sumWithNo2Contigious(int input[], int n);
int table[50];
void initialize()
{
	for(int i = 0; i<50; i++)
		table[i] = 0;
}

int main()
{
	int input[] = {-2, 11, -4, 13, -5, 2, 9, 34, 21};
	int n;
	initialize();
	n = sizeof(input)/sizeof(int);

	cout<<"\n The max sum, without selecting 2 contigious numbers is: "<< sumWithNo2Contigious(input, n)<<endl;

}
int sumWithNo2Contigious(int input[], int n)
{
	table[0] = input[0];
	table[1] = ((input[0]>input[1])?input[0]:input[1]);

	for(int i = 2; i<n; i++)
	{
		table[i] = (((table[i-2]+input[2])>table[i-1])?(table[i-2]+input[2]):table[i-1]);
	}
	int maxSum = 0;
	for(int i = 0; i<n; i++)
	{
		if(table[i]>maxSum)
			maxSum = table[i];
	}
	return maxSum;
}
