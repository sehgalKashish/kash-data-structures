#include<iostream>
#include<string>

using namespace std;

#define MAX 7

int partition(int arr[], int low, int high);

int main()
{
	/************************************************************************
	String array and char array were defined with null
	character in between "Zscaler \0 career" asked about 
	the length and output after printing.
	*************************************************************************/
	/*
	int n;
	char ch[20] = "zsca ler\0is";
	string st = "ka\0is";
	printf("%s \n", ch);
	printf("\n %d \n",strlen(ch));
	cout<<st;
	cout<<endl;
	*/
	/*****************************************************************
	a[2][3]={1,2,3,4,5,6} output of *(a[0]+2) *(*(a)+1) 1[[a]]
	******************************************************************/
	/*
	int a[2][3]={11,21,31,41,51,61};
	//cout<<(a[0][1]);
	cout<<*(a[1]+2);//61
	cout<<*(*(a)+1);//21
	cout<<endl;
	*/
	int arr[MAX] = {21, -34, 56, 9, -56, 90, -3};
	for(int i = 0; i<MAX; i++)
		cout<<"\t"<<arr[i];
	int low, high;
	low = 0;
	high = MAX-1;
	int pivot = partition(arr, low, high);//TODO proper ans not coming
	cout<<endl;
	for(int i = 0; i<MAX; i++)
		cout<<"\t"<<arr[i];
}

int partition(int arr[], int low, int high)
{
	int left, right;
	left = low;
	int pivot = 0;
	//while(left<right)
	for(int right = 0; right<=high; right++)
	{
		while(pivot>arr[left])
			left++;
		/*while(pivot<=arr[right])
			right--;*/
		if(left<right)
		{
			arr[left] = arr[left]+arr[right];
			arr[right] = arr[left]-arr[right];
			arr[left] = arr[left]-arr[right];
		}
	}
	//arr[low] = arr[right];
	//arr[right] = pivot;
	return left+1;
}