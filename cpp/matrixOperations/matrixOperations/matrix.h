#include<iostream>
using namespace std;

//#define MAX 10
//
//void getMatrix(int arr[][MAX], int m, int n);// style1 of passing a 2d matrix
//void Display(int arr[][MAX], int m, int n);
//void addition(int arr[][MAX], int brr[][MAX], int crr[][MAX], int r, int c);//for adding purpose
//
//
////void getMatrix(int *arr, int m, int n);//style2 of passing a 2d matrix
////void Display(int *arr, int m, int n);



void main()
{
	char ch[8]='Sasmita';
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<ch[(i+j)%7)];
		}
		cout<<endl;
	}
}
	