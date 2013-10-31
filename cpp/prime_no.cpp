#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	  int n,i,r,c;
	  cout<<"enter a no.";
	  cin>>n;
	  c=0;
	  for(i=2;i<sqrt(n);i++)
	  {
			if(n%i==0)
			c++;
	  }
	  if(c==0)
	  cout<<"\nno. is a prime no.\n";
	  else
	  cout<<"no. is not a prime\n";
	 // getch();
 }

