//TODO

#include<iostream>

using namespace std;

int matrixMultiplication(int p[], int n);

int table[6][6];

int main()
{
	int p[] = {10, 20, 30, 40, 30};
	int n = sizeof(p)/sizeof(int);
	cout<<"\n The minimum matrix multiplication cost is : "<<matrixMultiplication(p, n)<<endl;

	return 0;
}

int matrixMultiplication(int p[], int n)
{
	for(int i = 0; i <= n; i++)
	{
		table[i][i] = 0;	//setting diagonal as 0
	}

	for(int len = 2; len <= n; len++)
	{
		//for every position i, we check the chain of length len
		for(int i = 1; i <= (n - len + 1); i++)
		{
			int j = n - len + 1;
			table[i][j] = 9999999;
			/* For matrix i to j, check every split K */
             for(int k=i; k < j; k++)
			 {
                 int temp = table[i][k] + table[k+1][j] + p[i-1] * p[k] * p[j];
                /* Check if the current count is less than minimum */
                 if(temp < table[i][j])
				 {
                      table[i][j] = temp;                 
                 }
			 }
		}
	}
	return table[1][n];
}
