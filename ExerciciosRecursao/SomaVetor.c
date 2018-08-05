#include <stdio.h>

#define SIZE 5

int soma_vet(int n, int v[]);

int main ()
{
	int i, v[SIZE];
	for (i = 0; i < SIZE; i++) {
		printf("Digite o numero %d: ", i+1);
		scanf("%d", &v[i]);
	}
	printf("%d\n", soma_vet(SIZE, v));
}

int soma_vet(int n, int v[])
{	
	if (n == 1) return v[n - 1];
	else return v[n - 1] + soma_vet(n - 1, v);
}
