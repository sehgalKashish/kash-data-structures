#include<iostream>
#include<string.h>
#include"tree.h"

using namespace std;

int main()
{
	tree t1;
	struct node *root = t1.insert(6);
	root->left=t1.insert(23);
	root->right= t1.insert(34);
	root->left->left=t1.insert(17);
	root->left->right=t1.insert(43);
	root->right->left=t1.insert(20);
	//t1.preorder(root);
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
	
	cout<<endl<<"the Tree size(no. of elements are: "<<t1.preorder(root);
}