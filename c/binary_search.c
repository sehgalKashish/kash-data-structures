#include<conio.h>
#include<stdio.h>
int binsearch(int list[],int searchval,int left,int right);
void main()
{
	 int list[100],i,n,searchval,res,left,right;
	 printf("enter the no.of terms:");
	 scanf("%d",&n);
	 printf("enter the list in sorted order");
	 for(i=0;i<n;i++)
		  scanf("%d",&list[i]);
		  for(i=0;i<n;i++)
		  printf("\n%d",list[i]);
	 printf("\nenter the no.u wanna search");
	 scanf("%d",&searchval);
	 left=0;
    right=n-1;
	 res=binsearch(list,searchval,left,right);
	 printf("\nthe position is %d",res+1);
	 getch();
}
int binsearch(int list[],int searchval,int left,int right)
{
	 int mid;

	 while(left<=right)
	 {
		  mid=(left+right)/2;
		  if(searchval<list[mid])
		  return binsearch(list,searchval,left,mid-1);
		  else if(searchval>list[mid])
		  return binsearch(list,searchval,mid+1,right);
		  else
		  return mid;
		  }
		  return -2;

}
