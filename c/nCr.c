//nCr using recursion......
#include<stdio.h>
int fact(int m);
void main()
{
	  long int n,r,x,y,z,val,v;
	  printf("enter the value of n:");
	  scanf("\n%d",&n);
	  printf("\nenter the value of r:");
	  scanf("\n%d",&r);
	  if(n<r)
	  {
			printf("nCr not possible....!");

			}
	  else
	  {
			x=fact(n);
			y=fact(n-r);
			z=fact(r);
			val=x/(y*z);
			printf("the value of nCr is :%d",val);
	  }
	  //getch();
}
fact(m)
{
	 int k=1;
	 if(m==1)
	 return(1);
	 else
	 k=m*fact(m-1);
	 return (k);
}


