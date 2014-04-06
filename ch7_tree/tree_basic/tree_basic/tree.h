#include<iostream>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

class tree
{
private:

public:
	tree(){}
	node* insert(int data);
	int preorder(node *root);/*Traverse the tree in prre order*/
	void inorder(node *root);
	void postorder(node *root);
	int treeHeight(node *root);/*finds the max height of tree*/
	int identical(node *root, node *root1);/*to find whether two trees are identical or not*/
	//int tree_size(node *root);/*to determine tree size*/
};