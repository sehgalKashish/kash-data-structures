#include<iostream>

using namespace std;

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int i, int n);

int main()
{
	char a[] = "abcd";
	permute(a, 0, 3);
}

void permute(char *a, int i, int n)
{
	int j;
	if(i == n)
		printf("\n %s", a);
	else
	{
		for(j = i; j <= n; j++)
		{
			swap((a+i), (a+j));
			permute(a, i+1, n);
			swap((a+i), (a+j));
		}
	}
}