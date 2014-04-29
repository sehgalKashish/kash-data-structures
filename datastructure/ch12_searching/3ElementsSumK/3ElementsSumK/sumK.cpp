#include"sumK.h"

void getArray(int arr[], int n)
{
	cout<<"\n enter the arrray elements...: ";
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
}
/*
void bruteForceSearch(int arr[], int n, int k)
{
	int x = 0, y = 0, z = 0;
	for( x = 0; x < n; x++)
	{
		for(y = x+1; y<n;y++)
		{
			for(z = y+1; z<n; z++)
			{
				if(arr[x]+arr[y]+arr[z] ==k)
				{
					cout<<"\nitems found... "<<arr[x] <<arr[y]<<arr[z];
					return;
				}
			}
		}
	}
	cout<<"\n sorry no such element found... ";
}
*/
/*
int lonelyInterger(int *arr, int n)
{
	int i, res;
	for(i = 0, res = 0; i < n; i++)
	{
		res = res ^ arr[i];
	}
	return res;
}
*/