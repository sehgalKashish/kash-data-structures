#include"heapsort.h"

struct Heap* createHeap(int capacity)
{
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	/*if(h == NULL)
	{
		cout<<"\n memory error";
		return;
	}*/
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int)*h->capacity);
	/*if(h->array==NULL)
	{
		cout<<"\n memory error";
		return;
	}*/
	return h;
}

void buildHeap(struct Heap*h, int arr[], int n)
{
	int i;
	if(h == NULL)
		return;
	/*while(n >= h->capacity)
		resizeHeap(h);*/
	for( i = 0; i < n; i++)
		h->array[i] = arr[i];
	h->count = n;
	for( i = n/2 -1; i >= 0; i--)
		percolateDown(h, i);
}

void resizeHeap(struct Heap *h)
{
	int i;
	int *array_old = h->array;
	h->array = (int *)malloc(sizeof(int)*h->capacity*2);
	if(h->array == NULL)
	{
		cout<<"\n memory error";
		return;
	}
	for( i = 0; i < h->capacity; i++)
	{
		h->array[i] = array_old[i];
	}
	h->capacity *=2;
	free(array_old);
}

void percolateDown(struct Heap* h, int i)
{
	int l, r, max, temp;
	l = leftChild(h, i);
	r = rightChild(h, i);
	if(l!= -1 && h->array[l] > h->array[i])
		max = l;
	else
		max = i;
	if(r!= -1 && h->array[r] > h->array[max])
		max = r;
	if(max!=i)
	{
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[i] = temp;
	}
	percolateDown(h, max);
}

int leftChild(struct Heap* h, int i)
{
	int left = 2*i+1;
	if(left >= h->count)
		return -1;
	return left;
}

int rightChild(struct Heap* h, int i)
{
	int right = 2*i+2;
	if(right>=h->count)
		return -1;
	return right;
}

void heapsort(int arr[], int n)
{
	struct Heap *h = createHeap(n);
	int old_size, i, temp;
	buildHeap(h, arr, n);
	old_size = h->count;
	for(i = n-1; i>0; i++)
	{
		//h->array[0] is the largest element,
		temp = h->array[0];
		h->array[0]=h->array[h->count-1];
		h->array[0] = temp;
		h->count--;
		percolateDown(h, i);
	}
	h->count = old_size;
}

