#include<iostream>
#include<string.h>
#include"tree.h"

using namespace std;

int main()
{
	tree t1;
	int height = 0;
	struct node *root = t1.insert(6);
	root->left=t1.insert(23);
	root->right= t1.insert(39);
	root->left->left=t1.insert(17);
	root->left->right=t1.insert(43);
	root->right->left=t1.insert(20);
	//t1.preorder(root);
	//t1.iterativePreOrderTraversel(root);//THIS IS THE FUNCTION CALL
	/**************************************************************
	The following code is written to create another tree
	struct node *root1 = t1.insert(6);
	root1->left=t1.insert(23);
	root1->right= t1.insert(39);
	root1->left->left=t1.insert(17);
	root1->left->right=t1.insert(43);
	root1->right->left=t1.insert(20);
	char *s1 = ((t1.identical(root,root1))?"identical":"naah, you got it wrong");
	cout<<endl<<"trees are:"<<s1;
	***************************************************************/
	//cout<<endl<<"Max Height is : "<<t1.treeHeight(root)<<endl;
	
	//cout<<"\n The size of tree is : "<<t1.tree_size(root);
	cout<<"\n The tree elements in level order are: ";
	t1.levelOrderTraversel(root);

	cout<<"\n The tree elements in Zig-Zag order are: ";
	t1.zigZagTraversel(root);
	//t1.del_tree(root);
	//cout<<"\n diameter of tree is : "<<t1.diameterOfTree(root, &height);
	//t1.printAllAncestorNode(root,20);
	struct node* m1 = t1.LCA(root, 17,43);
	cout<<"\n LCA of 17 and 43 is \n"<< m1->data;
}