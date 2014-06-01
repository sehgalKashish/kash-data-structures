#include"matrix.h"

int main()
{
	int m, n, k, l, mat1[MAX][MAX], mat2[MAX][MAX], mat3[MAX][MAX];
	cout<<"\n enter the matrx 1 size [rows] & [columns]";
	cin>>m>>n;
	cout<<"\n enter the input matrix";
	getMatrix(mat1,m,n);// STYLE 1, in this one of the paramenter is req.
	//getMatrix(mat1,m,n);//STYLE 2, no parameter is req.
	cout<<"\n the input matrix is :\n";
	Display(mat1, m, n);
	
	cout<<"\n enter the matrx 2 size [rows] & [columns]";
	cin>>k>>l;
	cout<<"\n enter the input matrix";
	getMatrix(mat2,k,l);
	cout<<"\n the input matrix is :\n";
	Display(mat2, k, l);

	addition(mat1, mat2, mat3, m, n);
	Display(mat3, m, n);
	
	
}
