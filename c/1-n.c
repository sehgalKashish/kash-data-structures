/************Program to print no. 1 to n via recursion***********/
#include<stdio.h>

void Print(int N);

int main()
{
	int n;
	printf("enter the no.");
	scanf("%d", &n);
	Print(n);
	return;
}

void Print(int n)
{
	if(n == 0)
		return;
	else
	{
		Print(n-1);
		printf("\n%d ", n);
	}
	return;
}
