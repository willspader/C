// [Sedgewick 17.40]  Escreva uma função GRAPHindeg() que calcule o grau de entrada de um vértice v de um grafo G.

#include <stdio.h>
#include <stdlib.h>

#define vertex int

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
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

int GRAPHindeg( Graph G, vertex v) {
	int count = 0;
	link a;
	for (a = G->adj[v]; a != NULL; a = a->next, count++);
	return count;
}

int main()
{
	Graph G = GRAPHinit( 8);
	
	GRAPHinsertArc( G, 0, 1);
	GRAPHinsertArc( G, 1, 0);
	GRAPHinsertArc( G, 2, 1);
	GRAPHinsertArc( G, 3, 0);
	GRAPHinsertArc( G, 7, 2);
	GRAPHinsertArc( G, 3, 5);
	GRAPHinsertArc( G, 6, 1);
	
	vertex* isSource = malloc( G->V * sizeof( vertex));
	int grauEntrada = GRAPHindeg( G, 3);
	
	printf("Grau de saida do vertice 3: %d\n", grauEntrada);
	
	return 0;
}
