// string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
void main()
{
	char ch[4]="abc";
	cout<<"\n Permutations are::";
	perm(*ch,0,2);
}
void perm(char * ch)
{
	int l=strlen(ch);
	for(int i=0;i<l;i++)
	{
		
		for(int j=0;j<3;j++)
		{
			cout<<ch[i];
			//cout<<ch[(i+j)%7];
		}
		cout<<endl;
	}
}