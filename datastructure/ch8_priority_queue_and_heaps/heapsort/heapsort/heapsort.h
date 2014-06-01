#include<iostream>
#define MAX 3
using namespace std;

struct Heap
{
	int *array;
	int count;
	int capacity;
};

struct Heap* createHeap(int capacity);
void resizeHeap(struct Heap* h);
int leftChild(struct Heap* h, int i);
int rightChild(struct Heap* h, int i);
void percolateDown(struct Heap* h, int i);
void heapsort(int arr[], int n);
void buildHeap(struct Heap* h, int arr[], int n);
void percolateDown(struct Heap* h, int i);