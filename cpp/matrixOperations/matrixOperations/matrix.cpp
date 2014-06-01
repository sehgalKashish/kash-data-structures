#include"matrix.h"

/***********************************************************
style 1
**********************************************************/

void getMatrix(int mat[][MAX], int m, int n)
{
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>mat[i][j];
		}
	}
}

void Display(int mat[][MAX], int m, int n)
{
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<"	  "<<mat[i][j];
		}
		cout<<endl;
	}
}
void addition(int mat1[][MAX], int mat2[][MAX], int mat3[][MAX], int m, int n)
{
	for(int i = 0; i<m;i++)
	{
		for(int j = 0; j<n; j++)
		{
			mat3[i][j] = mat1[i][j]+mat2[i][j];
		}
	}
}

/***************************************************************
style 2
****************************************************************/
/*
void getMatrix(int *mat, int m, int n)
{
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>mat[i*n+j];
		}
	}
}
void Display(int *mat, int m, int n)
{
	for(int i = 0; i<m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<"	  "<<mat[i*n+j];
		}
		cout<<endl;
	}
}
*/
