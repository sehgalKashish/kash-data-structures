#include"binaryTree.h"

int main()
{
	
	struct node *root = NULL;
	tree t1, t2;
	t1.insert(&root, 25);
	t1.insert(&root, 10);
	t1.insert(&root, 35);
	t1.insert(&root, 15);
	t1.insert(&root, 20);
	t1.insert(&root, 30);
	t1.insert(&root, 40);
	t1.insert(&root, 45);
	t1.preorder(root);
	/*************************************************************/
	if(t1.find(root, 37))			//finding a number.
		cout<<"\n element exits...";
	else
		cout<<"\n sorry my bad...";
	/*************************************************************/
	if(t1.LCA(root, 10,45))			//finding LCA
		cout<<"\n the LCA is : "<<t1.LCA(root, 10, 45)->data;
	else
		cout<<"\n sorry my bad...";
	/*******************************************************************/
	t1.rangePrinter(root, 10, 34);

	cout<<"\n the kth smallest element  is : "<<t1.kthSmallestNode(root, 3, count)->data;

	if(t1.IsBST(root))
		cout<<"\n yes, it is a binary tree... ";
	else
		cout<<"\n not binart tree.. :  ";
	/*********************************************************************/
	cout<<"\n ######################################################################\n\n";
	int arr[] = {4, 34, 67, 1, 89, 73, 35, 8};
	/*int left, right;
	left = 0; 
	right = MAX-1;
	t2.preorder(t2.buildBst(arr, left, right));
	*/
	struct node *root1 = NULL;
	for(int i = 0; i< MAX; i++)
		t2.insert(&root1, arr[i]);
	t2.preorder(root1);

}
