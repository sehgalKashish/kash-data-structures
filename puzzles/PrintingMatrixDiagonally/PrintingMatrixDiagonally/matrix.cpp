/*printing a matrix diagonally
The sum of indexes of each matrix element in each stripe is constant
*/

#include<iostream>

using namespace std;

#define MAX 7

int main()
{
	int arr[][4] = {1,2,3,4,
					5,6,7,8,
					9,10,11,12,
					13,14,15,16
					};
	int m, n, sum;
	m = n = 4;
	sum = m+n-1;
	for(int i=0; i<sum;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(j+k-i==0)
				{
					cout<<arr[j][k]<<"	";
				}
			}
		}
		cout<<endl;
	}
}



					