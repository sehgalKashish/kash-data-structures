#include"qsort.h"
/*this is the main quick sort algo*/
void quicksort(int ar[], int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot = partition(ar, low, high);
		quicksort(ar, low, pivot-1);
		quicksort(ar, pivot+1, high);
	}
}
/*this partition function finds the exact position of pivot element*/
int partition(int ar[], int low, int high)
{
	int left, right;
	int pivot_item;
	pivot_item = ar[low];
	left = low;
	right = high;

	while(left<right)//loops till left is less than right
	{
		while(ar[left]<=pivot_item)//pivot should be placed such that its left elements should be less than or equal it
			left++;
		while(ar[right]>pivot_item)//elements on right should be greated than pivot
			right--;
		if(left<right)//if the counters, left and right exchange, than swap ar[left] and ar[right]
		{
			ar[left] = ar[left]+ar[right];
			ar[right] = ar[left]-ar[right];
			ar[left] = ar[left]-ar[right];
		}
	}
	ar[low] = ar[right];/* In the end, make right element as new left, and right as pivot, 
						which has reached its correct place.
						*/
	ar[right] = pivot_item;
	return right;
}
