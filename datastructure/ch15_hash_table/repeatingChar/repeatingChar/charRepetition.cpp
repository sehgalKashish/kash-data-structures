/********************************************************************
Give an algorithm for printing first repeated character in a string
*********************************************************************/
#include<iostream>
#include<string>
using namespace std;
#define MAX 256
char firstRepeatedChar(char *str);

int main()
{
	char str[] = {'a','b','c','e','s','c','b','c','c','e','b','c'};
	firstRepeatedChar(str);
}

char firstRepeatedChar(char *str)
{
	int hash[256];
	int length = strlen(str);
	for(int i = 0; i<256; i++)
		hash[i] = 0;
	for(int i = 0; i<length; i++)
	{
		if(hash[str[i]]==1)
		{
			cout<<"\n First repeated char is : "<<str[i];
			break;
		}
		else
			hash[str[i]]++;
	}
	return 0;
}


