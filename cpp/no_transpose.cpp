#include<iostream>

using namespace std;

int main()
{
	int a, count, i, b, j, temp;
	count = i = temp = 0;
	int iarr[10];

	cout<<"\nenter the number : ";
	cin>>a;
	while(a)
	{
		iarr[i] = a%10;
		a = a/10;
		count++; i++;
	}
	for(i = 0; i < count; i++)
	{
		cout<<"\n no. in array being : "<<iarr[i];
	}
	//sorting algo
	for(i = 0; i < count-1; i++)
    	{
        	for(j = 0;j <count-i-1; j++)
        	{
            		if(iarr[j] > iarr[j+1])
            		{
                		int temp;
                		temp = iarr[j];
                		iarr[j] = iarr[j+1];
                		iarr[j+1] = temp;
            		}
        	}
    	}//end
	for(i = 0; i < count; i++)
        {
                cout<<"\n the sorted array being : "<<iarr[i];
        }


	for(i = 0; i < count; i++)
	{
		if(iarr[i] != 0)
			break;
	}
	temp = iarr[0];
	iarr[0] = iarr[i];
	iarr[i] = temp;
	for(i = 0; i < count; i++)
        {
                cout<<"\n no. after removing first 0 being : "<<iarr[i];
        }

	b = iarr[0];
	for(i = 1; i < count; i++)
	{
		b = b*10 + iarr[i];
	}
	cout<<"\n the lowest transpose is : "<<b;
	return 0;
}
