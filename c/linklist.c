#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *start,*last,*temp;
start = last = temp = NULL;

void add_element(node **start,node **last,node **temp);
void del(node *start);
void display(node *start);

int main()
{
    int n;
    char ch;
    printf("select the operation to be performed on link list:");
    do
    {
        printf("\n1.add_element\t\t2.delete_element\t\t3.display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                add_element(&start,&last,&temp);
                break;
            case 2:
                del(start);
                break;
            case 3:
                display(start);
                break;
        }
        printf("\ndo you wish to continue..y/n??");
        fflush(stdin);
        scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
}
void add_element(node **start,node **last,node **temp)
{
    int dat;
    printf("\nenter the data to be inserted");
    scanf("%d",&dat);
    if((*start)==NULL)
    {
        (*start)=(node*)malloc(sizeof(node));
        (*start)->data=dat;
        (*start)->next=NULL;
        (*last)=(*start);
    }
    else
    {
        (*temp)=(node*)malloc(sizeof(node));
        (*temp)->data=dat;
        (*last)->next=*temp;
        (*temp)->next=NULL;
        (*last)=(*temp);
    }
}
void del(node *start)
{
    int n;
    temp=start;
    printf("enter the node to be deleted:");
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
        temp=temp->next;
    temp->next=(temp->next)->next;
    free(temp->next);
}
void display(node *start)
{
    temp=start;
    while(temp!=NULL)
    {
	printf("%5d",temp->data);
	temp=temp->next;
    }
}

