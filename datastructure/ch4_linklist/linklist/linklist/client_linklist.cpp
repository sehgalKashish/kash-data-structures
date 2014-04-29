#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	node *next;
};
struct node *start, *last;

void insert(int data);
void Display();
int main()
{
	insert(5);
	insert(8);
	Display();
	LARGE_INTEGER A;
}
void insert(int data)
{
	struct node *temp;
	*temp=(node*)malloc(sizeof(node));
	if(start==NULL)
	{
		temp->data = data;
		temp->next = NULL;
		start = temp;
		last = temp;
	}
	else
	{
		*start = *temp;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->data = data;
		temp->next = NULL;
		last = temp;
	}
}
void Display()
{
	struct node *temp;
	*temp=(node*)malloc(sizeof(node));
	*temp = *start;
	while(temp->next!=NULL)
	{
		printf(" %d -> ", temp->data);
	}
}
