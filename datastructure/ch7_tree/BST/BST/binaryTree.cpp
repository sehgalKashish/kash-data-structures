#include"binaryTree.h"

void tree::insert(struct node **root, int data)
{
	if(*root==NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		if(*root==NULL)
			cout<<"\n Insufficient memory...";
		(*root)->data = data;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}
	else
	{
		if((*root)->data > data)
			insert(&(*root)->lchild, data);
		else if((*root)->data < data)
			insert(&(*root)->rchild, data);
	}
}


void tree::preorder(node *root)
{
	if(root!=NULL)
	{
		preorder(root->lchild);
		cout<<"  "<<root->data;
		preorder(root->rchild);
	}
}

struct node* tree::find(node *root, int data)
{
	if(!root)
		return 0;
	if(root->data == data)
		return root;
	else if((root->data) > data)
		find(root->lchild, data);
	else if((root->data) < data)
		find(root->rchild, data);
}

struct node* tree::LCA(node *root, int a, int b)
{
	if((a<(root->data) && b>(root->data))||(b<(root->data) && a>(root->data)))
		return root;
	else if((a>root->data)&&(b>root->data))
		LCA(root->rchild, a, b);
	else if((a<root->data)&&(b<root->data))
		LCA(root->lchild, a, b);
}

int tree::IsBST(node *root)
{
	if(root==NULL)
		return 0;
	if((root->lchild!=NULL)&&max(root->lchild)>root->data)
		return 0;
	if((root->rchild!=NULL)&&min(root->rchild)<root->data)
		return 0;
	if(!IsBST(root->lchild)||!IsBST(root->rchild))
		return 0;
	else
		return 1;
}
struct node* tree::buildBst(int arr[], int left, int right)
{
	int mid;
	struct node* newNode;
	if(left>right)
		return NULL;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(!newNode)
		cout<<"\nMemory error.... ";
	if(left==right)
	{
		newNode->data = arr[left];
		newNode->lchild = newNode->rchild = NULL;
	}
	else
	{
		mid = (left+right)/2;
		newNode->data = arr[mid];
		newNode->lchild = buildBst(arr, left, mid-1);
		newNode->rchild = buildBst(arr, mid+1, right);
	}
	return newNode;
}

void tree::rangePrinter(node *root, int k1, int k2)
{
	if(root==NULL)
		return;
	if(root->data > k1)
		rangePrinter(root->lchild, k1, k2);
	if((root->data > k1)&& (root->data < k2))
		cout<<"\n  "<<root->data;
	if(root->data < k2)
		rangePrinter(root->rchild, k1, k2);
}
struct node* tree::kthSmallestNode(struct node *root, int k, int count)
{
	struct node* left;
	if(!root)
		return NULL;
	left = kthSmallestNode(root->lchild, k, count);
	if(left)
		return left;
	else if(++count == k)
		return root;
	else
		return kthSmallestNode(root->rchild, k, count);
}


int tree::max(node *root)
{
	if(root==NULL)
		return NULL;
	else
		if(root->rchild==NULL)
			return (root->data);
		else
			max(root->rchild);
}

int tree::min(node *root)
{
	if(root==NULL)
		return NULL;
	else
		if(root->lchild==NULL)
			return (root->data);
		else
			min(root->lchild);
}


