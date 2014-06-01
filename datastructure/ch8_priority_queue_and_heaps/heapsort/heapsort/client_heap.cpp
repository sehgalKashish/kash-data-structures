#include"heapsort.h"

int main()
{
	int ar[MAX];
	cout<<"\n enter the array elements: ";
	for(int i = 0; i < MAX; i++)
	{
		cin>>ar[i];
	}
	heapsort(ar, MAX);
	cout<<"\n Array after sort is : ";
	for(int i = 0; i < MAX; i++)
	{
		cout<<"   "<<ar[i];
	}
}