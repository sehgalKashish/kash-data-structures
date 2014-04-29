#include<iostream>
#include<stack>

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
	void preorder(node *root);/*Traverse the tree in prre order*/

	void iterativePreOrderTraversel(node *root);//traverse preorder, iteratively, using stack...!!!

	void inorder(node *root);

	void postorder(node *root);

	int treeHeight(node *root);/*finds the max height of tree*/

	int identical(node *root, node *root1);/*to find whether two trees are identical or not*/

	int tree_size(node *root);/*to determine tree size*/

	int diameterOfTree(node *root, int *height);/*The diameter of a tree (sometimes called the width)
											   is the number of nodes on the longest path 
											   between two leaves in the tree.*/

	int max(int left, int right);

	int printAllAncestorNode(struct node *root, int target);

	struct node *LCA(struct node *root, int n1, int n2);

	void del_tree(node *root);
};