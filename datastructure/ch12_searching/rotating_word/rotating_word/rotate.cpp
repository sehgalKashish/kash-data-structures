/********************************************************************
Write a program to print all the rotations of a number.
Like , if the word is abc, then, it should print abc, bca, cab
*********************************************************************/

#include<iostream>

using namespace std;

int main()
{
	char st[10] = "kashinath";
	int x = strlen(st);
	cout<<x<<endl;
	for(int i = 0; i<strlen(st); i++)
	{
		for (int j = 0; j<strlen(st); j++)
		{
			cout<<st[(j+i)%x];
		}
		cout<<endl;
	}

}