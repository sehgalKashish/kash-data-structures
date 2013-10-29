/*fibonaci series using recursion*/
#include<stdio.h>
#include<conio.h>
void fib_rec(int n,int i,int fib[50]);
void main()
{
	 int n,j,fib[50];
	 printf("\n\nenter the term till which series is to be printed:\n\n");
	 scanf("%d",&n);
	 fib_rec(n,2,fib);
	 printf("\nthe fibonaci sreies is:\n");
	 for(j=0;j<n;j++)
	 {
		 printf("%5d",fib[j]);
	 }
	 getch();
	 }
void fib_rec(int n,int i,int fib[50])
{
	fib[0]=0;
	fib[1]=1;
	if(i<=n)
	{
		fib[i]=fib[i-1]+fib[i-2];
		i++;
		fib_rec(n,i,fib);
	}
}
