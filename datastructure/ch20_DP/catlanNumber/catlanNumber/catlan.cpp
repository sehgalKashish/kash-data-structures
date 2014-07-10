/**
* The number of bst's with n nodes is called CATLAN NUMBER.
* It is denoted by Cn.
* catlan number for a fixed value of i is Ci-1*Cn-i.
**/
#include<iostream>

using namespace std;

int table[1024];
int catlanNumber(int n);
int catlanNumberDynamic(int n);

int main()
{
	int n;
	cout<<"\n enter the number of nodes of the bst : ";
	cin>>n;
	cout<<"\n the number of bst with "<<n<<"nodes is (dynamic method) : "<<catlanNumberDynamic(n)<<endl;
	cout<<"\n the number of bst with "<<n<<"nodes is : "<<catlanNumber(n);

	return 0;
}

int catlanNumberDynamic(int n)
{
	table[0] = table[1] = 1;
	for(int i = 2; i <=n; i++)
	{
		table[i] = 0;
		for(int j = 0; j < i; j++)
		{
			table[i] += table[j]*table[i-j-1];
		}
	}
	return table[n];
}

int catlanNumber(int n)
{
	if(n==0)
		return 1;
	int count = 0;
	for(int i = 1; i<= n; i++)
	{
		count +=catlanNumber(i-1) * catlanNumber(n-i);
	}
	return count;
}