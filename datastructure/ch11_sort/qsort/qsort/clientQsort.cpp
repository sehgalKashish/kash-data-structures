#include"qsort.h"

int main()
{
	int ar[MAX];
	int low, high;
	cout<<"\n enter the array elements: ";
	for(int i = 0; i < MAX; i++)
	{
		cin>>ar[i];
	}
	low = 0;
	high = MAX-1;
	quicksort(ar, low, high);
	cout<<"\n Array after sort is : ";
	for(int i = 0; i < MAX; i++)
	{
		cout<<"   "<<ar[i];
	}

}

