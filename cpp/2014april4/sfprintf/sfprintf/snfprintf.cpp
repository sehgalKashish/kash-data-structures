#include<iostream>

using namespace std;

int main()
{
	char fir[50] = "first str";
	char * sec = "second str";
	char res[50];

	sprintf(fir, "%s kashish %s", fir, sec);
	//snprintf(fir, 10, "%s kashish %s", fir, sec);//snprintf take one more arg which specifies the size of buffer.
	printf("%s\n", fir);
}