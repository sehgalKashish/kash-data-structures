#include"sumK.h"


int main()
{
	int arr[MAX];
	int i, n, k, res;
	cout<<"\n enter the no. of elements is array.. ";
	cin>>n;
	getArray(arr,n);
	/*
	cout<<"\n enter the no. which should be equal to sum...";
	cin>>k;
	bruteForceSearch(arr,n,k);
	*/
	//p = lonelyInteger(arr,n);
	for(i = 0, res = 0; i < n; i++)
	{
		res = res ^ arr[i];
	}
	cout<<"\n the element which appears single time is.. : "<<res;

	return 0;
}

