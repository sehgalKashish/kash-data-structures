#include"tree.h"

using namespace std;

node* tree ::insert(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node-> data = data;
	node-> left= NULL;
	node-> right = NULL;

	return (node);
}
void tree::preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<endl<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}


void tree::iterativePreOrderTraversel(struct node *root)
{
	if (root == NULL)
		return;
	stack<node*> myStack;
	myStack.push(root);
	while (!myStack.empty())
	{
		struct node *node = myStack.top();
		cout<<node->data<<"\t";
		myStack.pop();
		if (node->right)
			myStack.push(node->right);
		if (node->left)
			myStack.push(node->left);
	}
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

int tree::tree_size(struct node *root)
{
	if(root==NULL)
		return 0;
	else
		return (tree_size(root->left)+1+tree_size(root->right));//returns the size of tree. left and right.
}

int tree::diameterOfTree(struct node *root, int *height)
{
	int left, right;
	if(!root)
		return 0;
	left = diameterOfTree(root->left, &left);
	right = diameterOfTree(root->right, &right);

	if(left+right>*height)
		*height = left+right;
	return max(left,right)+1;
}

int tree::max(int left, int right)
{
	return ((left>right)?left:right);
}

int tree::printAllAncestorNode(node *root, int target)
{
	if(root==NULL)
		return 0;
	if(root->data==target||printAllAncestorNode(root->left,target)
		||printAllAncestorNode(root->right,target))
	{
		cout<<"-> "<<root->data;
		return 1;
	}
	return 0;
}

struct node * tree::LCA(node *root, int n1, int n2)
{
	struct node *left, *right;
	if(root==NULL)
		return root;
	if(root->data==n1||root->data==n2)
		return root;
	left = LCA(root->left,n1,n2);
	right = LCA(root->right,n1,n2);

	if(left&&right)
		return root;
	else
		return (left?left:right);
}

void tree::del_tree(struct node *root)
{
	if(root==NULL)
		return;
	del_tree(root->left);
	del_tree(root->right);

	cout<<"\n deleting item : "<<root->data;
	free(root);
}
		

		
