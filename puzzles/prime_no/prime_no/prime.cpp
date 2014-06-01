#include<iostream>
#include "math.h"
using namespace std;


#define MAX 10
int main()
{
	 int k;
	 int arr[MAX];
	 cout<<"\n enter no. :";
	 cin>>k;
	 int i = 0;
	 while(k)
	 {
		 arr[i] = k%10;
		 k = k/10;
		 i++;
	 }
	 int mx = arr[0];
	 int max_pos;
	 for(int j = i-1; j>=0; j--)
	 {
		 if(arr[j]>=mx)
		 {
			 mx = arr[j];
			max_pos=j;
			}
	 }
		int temp;
		temp=arr[i-1];
		arr[i-1]=arr[max_pos];
		arr[max_pos]=temp;
		int a=0,cnt=0,mult=1;
		while(cnt<i)
		{
			a+=arr[cnt]*mult;
			mult*=10;
			cnt++;
		}
		cout<<a;
		 
}