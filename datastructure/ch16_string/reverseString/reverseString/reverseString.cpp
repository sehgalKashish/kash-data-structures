#include<iostream>
#include<string>
using namespace std;

void reverse(char *str, int start, int end);
int main()
{
	char str1[] = "this is kashish sehgal";
	int length, start, end;
	length = strlen(str1);
	cout<<"\n sstring lenght is : "<<length<<endl;
	reverse(str1, 0, length-1);//reverses the whole string
	
	for(start = end = 0; end<length; end++)
	{
		if(str1[end]!= ' ')//looks for <space>
		{
			start = end;
			while(str1[end]!=' '&& end<length)
			{
				end++;
			}
			end--;
			reverse(str1, start, end);
		}
	}
	for( int i = 0; i<length; i++)
		cout<<str1[i];
}

void reverse(char *str, int start, int end)
{
	char temp;
	while(start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
