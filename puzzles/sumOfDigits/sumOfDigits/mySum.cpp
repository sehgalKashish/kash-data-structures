/*************************************************
Finds the sum of the digits.
If digit entered is 456, o/p will be 
4+5+6 = 15
1+5 = 6
*************************************************/
#include<iostream>

using namespace std;

int findSum(int n, int sum);

int main()
{
	int n, sum;
	sum = 0;
	cout<<"\n enter the number: ";
	cin>>n;
	cout<<"\n the sum of the digits is : "<<findSum(n, sum);
}

int findSum(int n, int sum)
{
	if(n==0)
	{
		if(sum<=10)
		{
			return sum;
		}
		else 
			return findSum(sum,0);
	}
	else
	{
		sum += n%10;
		n /= 10;
		return findSum(n, sum);
	}

}
