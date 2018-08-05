#include <stdio.h>
#include <stdlib.h>

#define vertex int

/* A lista de adjac�ncia de um v�rtice v � composta por n�s do tipo node. 
Cada n� da lista corresponde a um arco e cont�m um vizinho w de v e o endere�o do n� seguinte da lista. Um link � um ponteiro para um node. */

typedef struct node *link;
struct node { 
   vertex w; 
   link next; 
};

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A estrutura graph representa um grafo. 
O campo adj � um ponteiro para o vetor de listas de adjac�ncia, o campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de arcos do grafo. */

struct graph {
   int V; 
   int A; 
   link *adj; 
};

/* Um Graph � um ponteiro para um graph. */

typedef struct graph *Graph;

/* A fun��o NEWnode() recebe um v�rtice w e o endere�o next de um n� e devolve o endere�o a de um novo n� tal que a->w == w e a->next == next. */

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */

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

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o GRAPHinsertArc() insere um arco v-w no grafo G. A fun��o sup�e que v e w s�o distintos, 
positivos e menores que G->V. Se o grafo j� tem um arco v-w, a fun��o n�o faz nada. */

void GRAPHinsertArc( Graph G, vertex v, vertex w) {
	link a; 
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

int main()
{
	Graph G = GRAPHinit( 8);
	
	return 0;
}
