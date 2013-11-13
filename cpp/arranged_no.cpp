/******************** Arranged no.********************************
given 2 nos., output should be all the nos. between them,
having digits greater than preceding, and the count of such nos.
******************************************************************/
#include<iostream>

using namespace std;

int main()
{
	int i, j, x, count, k, flag;
	count = k = flag = 0;
	cout<<"\nenter the first no.";
	cin>>i;
	cout<<"enter the second no.";
	cin>>j;
	for(x = i; x < j; x++)
	{
		k = x;
		flag = 0;
		while(flag == 0)
		{
			if(k/10 == 0)
			{
				cout<<"\nnumber being : "<<x;
				flag = 1;
				count++;
				//cout<<"\ninside if";
			}
			else if(k%10 <= (k/10)%10)
			{
				flag = 1;
				//cout<<"\ninside else if";
			}
			else if(k%10 > (k/10)%10)
			{
				k = k/10;
				//cout<<"\ninside 2nd else if";
			}
		}
	}
	cout<<"total nos. are:"<<count<<"\n";
}
