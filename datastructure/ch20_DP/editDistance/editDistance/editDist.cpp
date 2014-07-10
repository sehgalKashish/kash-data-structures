#include<iostream>
#include<string>
using namespace std;

#define MAX 11
int getEditDistance (char *s, char *t);

int main()
{
	char *s = " saturday";
	char *t = " sunday";

	cout<<"\n The edit distance between "<<s<< "and "<<t<< " is : "<<getEditDistance (s, t);

}

int getEditDistance (char *s, char *t)
{
	if ( s == NULL || t == NULL)
		return -1;

	int m, n;
	m = strlen (s) + 1;
	n = strlen (t) + 1;
	int minimum = 0;
	int temp_min = 0;

	//int **table = (int **)malloc(m * n * sizeof(int));
	int table[MAX][MAX];
	memset (table, -1, sizeof(table));

	for (int i = 0; i < n; i++)
		table[i][0] = i;

	for (int i = 0; i < m; i++)
		table[0][i] = i;

	for (int i = 1; i <m; i++)
	{
		for (int j = 1; j <n; j++)
		{
			if (s[i-1] == t[j-1])
				temp_min = table[i-1][j-1];

			else 
				temp_min = table[i-1][j-1] + 1;

			if (table[i][j-1] > table[i-1][j])
				minimum = table[i-1][j] + 1;
			else 
				minimum = table[i][j-1] + 1;

			if (temp_min < minimum)
			{
				if (temp_min < minimum)
					minimum = temp_min;
			}
			table[i][j] = minimum;
		}
	}

	//Printint the table
    for(int i=1; i<n; i++)
	{
        for(int j=1; j<m; j++)
		{
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return table[n-1][m-1];
}
