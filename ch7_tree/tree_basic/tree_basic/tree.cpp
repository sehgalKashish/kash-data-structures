#include"tree.h"
#include<iostream>

using namespace std;

node* tree ::insert(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node-> data = data;
	node-> left= NULL;
	node-> right = NULL;

	return (node);
}
int tree::preorder(struct node *root)
{
	static int count;

	if(root!=NULL)
	{
		count++;
		cout<<endl<<root->data;
		preorder(root->left);
			
		preorder(root->right);
			//count++;
	}
	return count;
}
void tree::inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<endl<<root->data;
		inorder(root->right);
	}
}
void tree::postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<endl<<root->data;
	}
}

int tree::treeHeight(struct node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int lheight=treeHeight(root->left);
		int rheight=treeHeight(root->right);
		int max=((lheight>rheight)?(lheight+1):(rheight+1));
		return max;
	}
}
int tree::identical(struct node *root, struct node *root1)
{
	if(root==NULL&&root1==NULL)
		return 1;
    if(root!=NULL&&root1!=NULL)
	{
		return(root->data==root1->data&&identical(root->left,root1->left)&&identical(root->right,root1->right));
	}
	else
		return -1;
}
/*int tree::tree_size(struct node *root)
{
	static int count;
	if(root!=NULL)
	{
		//count++;
		inorder(root->left);
		cout<<endl<<root->data;
		count++;
		inorder(root->right);
	}
	return count;
}*/

		
