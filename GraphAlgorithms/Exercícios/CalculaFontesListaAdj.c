// escreva um programa que identifique as fontes de um grafo.

#include <stdio.h>
#include <stdlib.h>

#define vertex int
#define false 0
#define true 1

typedef struct node *link;
struct node { 
   vertex w; 
   link next; 
};

struct graph {
   int V; 
   int A; 
   link *adj; 
};
typedef struct graph *Graph;

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   vertex v;
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
	link a; 
	for (a = G->adj[v]; a != NULL; a = a->next) {
		if (a->w == w) return;
	}
	G->adj[v] = NEWnode( w, G->adj[v]);
	G->A++;
}

int sources( Graph G, vertex* isSource) {
	vertex v;
	link a;
	int flag = false;
	for (v = 0; v < G->V; v++) {
		isSource[v] = true;
	}
	for (v = 0; v < G->V; v++) {
		for (a = G->adj[v]; a != NULL; a = a->next) {
			isSource[a->w] = false;
			flag = true;
		}
	}
	return flag;
}

int main()
{
	Graph G = GRAPHinit( 8);
	
	GRAPHinsertArc( G, 0, 1);
	GRAPHinsertArc( G, 1, 0);
	GRAPHinsertArc( G, 2, 1);
	GRAPHinsertArc( G, 3, 0);
	GRAPHinsertArc( G, 7, 2);
	GRAPHinsertArc( G, 4, 5);
	GRAPHinsertArc( G, 6, 7);
	
	vertex* isSource = malloc( G->V * sizeof( vertex));
	sources( G, isSource);
	
	printf("1 - Vertice fonte\n0 - Vertice nao-fonte\n\n");
	
	vertex v;
	for (v = 0; v < G->V; v++) {
		printf( "Vertice %d : %d\t", v, isSource[v]);
	}
	printf("\n");
	
	return 0;
}
