#include<iostream>

using namespace std;
#define MAX 8

struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
static int count;
class tree
{
private:

public:
	void insert(struct node **root, int data);//insertion, so that original root also changes
	void preorder(struct node *root);
	struct node *find(node *root, int data);
	struct node *LCA(node *root, int a, int b);
	int IsBST(node *root);
	struct node *buildBst(int arr[], int left, int right);//for sorted array.
	void rangePrinter(node *root, int k1, int k2);
	struct node *kthSmallestNode(node *root, int k, int count);
	int min(node *root);//TODO not working
	int max(node *root);//TODO not working
};
