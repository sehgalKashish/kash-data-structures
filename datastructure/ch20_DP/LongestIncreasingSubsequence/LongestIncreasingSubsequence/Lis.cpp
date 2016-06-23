/********************************************************************************
LONGEST INCREASING SUBSEQUENCE
Given a sequence of n numbers, A1, A2, A3, ....An, determine a subsequence
(not necessarily contigious) of maximum length in which values in the sequence
form a strictly increasing sequence
*********************************************************************************/
#include<iostream>

using namespace std;
int LIST[10];
int LongestIncreasingSubsequence(int arr[], int size)
{
	int i, j, max = 0;
	for(i = 0; i<size; i++)
		LIST[i] = 1;	//Initialisation for the base case, i.e one element

	for(i = 0; i<size; i++)
	{
		for( j = 0; j < i; j++)
		{
			if( arr[i] > arr[j] && LIST[i]<LIST[j]+1)
				LIST[i] = LIST[j] + 1;
		}
	}
	for( i = 0; i < size; i++)
	{
		if( max < LIST[i])
			max = LIST[i];
	}
	return max;
}
int main()
{
	int arr[] = {2, 9, 6, 3, 8, 9};
	int size;
	size = sizeof(arr)/sizeof(int);
	cout<<"\n The size of longest increasing subsequence is : "<<LongestIncreasingSubsequence(arr,size)<<endl;


}