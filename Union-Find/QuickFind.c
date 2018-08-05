/*
 * Inicializa��o = N
 * Unir = N
 * Find = 1
 * Time complexity = O(n^2);
 */
#include <stdio.h>

#define MAX 10

int connected(int p, int q);
int unionn(int p, int q);

int id[MAX];

int main()
{
    // atribui o pr�pria �ndice como valor em cada posi��o do vetor
    for(int i = 0; i < MAX; i++)
    {
        id[i] = i;
    }

    unionn(4,3);
    unionn(3,8);
    unionn(6,5);
    unionn(9,4);
    unionn(2,1);
    printf("%d\n", connected(9,4));
    printf("%d\n", connected(5, 0));
    unionn(5,0);
    for(int i = 0; i < MAX; i++)
    {
        printf("%d\t", id[i]);
    }

    return 0;
}

// verifica se p est� conectado � q (equival�ncia)
int connected(int p, int q)
{
    return id[p] == id[q];
}

// fun��o para unir p � q
int unionn(int p, int q)
{
    int pid = id[p];
    int qid = id[q];
    for(int i = 0; i < MAX; i++)
    {
        if(id[i] == pid) id[i] = qid;
    }
}
