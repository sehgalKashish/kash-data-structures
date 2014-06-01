/*Adj matrix representation*/

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct graph 
{
	int v;
	int e;
	int **adj;//since we need a 2-d matrix
};
struct graph *adjMatrixOfGraph()
{
	int i, u , v;
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
		//printf("\n error....");
	printf("\n No. of vertices v, No. of edjes: e ");
	scanf("%d %d ", &g->v, &g->e);
	printf("\n No. of vertices %d, No. of edjes: %d ", g->v, g->e);
	g->adj=(int **)malloc(sizeof(g->v*g->e));

	for(u = 0; u<g->v; u++)
	{
		for(v = 0; v<g->v; v++)
			g->adj[u][v] = 0; //initalise the array to zero.
	}

	for(u = 0; u<g->v; u++)
	{
		//read an edje
		printf("\ read the edjes... ");
		scanf("%d %d ", &u,&v);

		//for undirected graph set both bits to one.
		g->adj[u][v] = 1;
		g->adj[v][u] = 1;

	}
	return g;
}


int main()
{
	adjMatrixOfGraph();

}