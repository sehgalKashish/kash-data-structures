#include<iostream.h>
#include<conio.h>
#include<math.h>
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
	  cout<<"\nno. is a prime no.";
	  else
	  cout<<"no. is not a prime";
	  getch();
 }

