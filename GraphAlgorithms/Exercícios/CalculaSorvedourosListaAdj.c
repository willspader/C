//Escreva uma função que identifique os sorvedouros de um grafo.

#include <stdio.h>
#include <stdlib.h>

#define vertex int
#define true 1
#define false 0

/* A lista de adjacência de um vértice v é composta por nós do tipo node. 
Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */

typedef struct node *link;
struct node { 
   vertex w; 
   link next; 
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo. 
O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */

struct graph {
   int V; 
   int A; 
   link *adj; 
};

/* Um Graph é um ponteiro para um graph. */

typedef struct graph *Graph;

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */

Graph GraphInit( int V) {
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   vertex v;
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, 
positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */

void GraphInsertArc( Graph G, vertex v, vertex w) {
	link a; 
	for (a = G->adj[v]; a != NULL; a = a->next) {
		if (a->w == w) return;
	}
	G->adj[v] = NEWnode( w, G->adj[v]);
	G->A++;
}

// summary: armazena os sorvedouros de um grafo G no vetor isSink
// returns: true se existe ao menos um sorvedouro ou false caso contrário.

int sinks( Graph G, vertex* isSink) {
	int flag = false;
	vertex v;
	for (v = 0; v < G->V; v++) {
		if(G->adj[v] == NULL) {
			isSink[v] = true;
			flag = true;
		}
		else {
			isSink[v] = false;
		}
	}
	return flag;
}

int main()
{
	Graph G = GraphInit( 8);
	
	vertex* isSink = malloc(G->V * sizeof( vertex));
	
	GraphInsertArc( G, 0, 1);
	GraphInsertArc( G, 1, 3);
	GraphInsertArc( G, 1, 2);
	GraphInsertArc( G, 0, 1);
	GraphInsertArc( G, 5, 4);
	GraphInsertArc( G, 2, 8);
	GraphInsertArc( G, 2, 7);
	GraphInsertArc( G, 6, 7);
	
	sinks( G, isSink);
	
	printf("1 - Vertice sorvedouro\n0 - Vertice nao-sorvedouro\n\n");
	vertex v;
	for (v = 0; v < G->V; v++) {
		printf( "vertice %d : %d\t", v, isSink[v]);
	}
	printf("\n");
	
	return 0;
}





