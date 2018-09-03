#include <stdio.h>

#define MAX 51

int isSafe(int lbr[MAX][MAX], int n, int i, int j);
int maze(int lbr[MAX][MAX], int n, int i, int j, int sol[MAX][MAX]);

int main()
{
	int n, i, j, lbr[MAX][MAX], sol[MAX][MAX];
	printf("Digite o tamanho do labirinto [MAX 50]: ");
	fscanf(stdin, "%d", &n);
	if (n >= MAX) {
		fprintf(stderr, "Tamanho do labirinto excede o permitido\n");
	}
	printf("\nPreencha o caminho do labirinto com 0s e 1s\n");
	lbr[0][0] = 1;
	lbr[n - 1][n - 1] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((i == 0 && j == 0) || (i == n - 1 && j == n - 1)) continue;
			fscanf(stdin, "%d", &lbr[i][j]);
		}
	}
	
	if (maze(lbr, n, n - 1, n - 1, sol))
	{
		printf("\n------ Resultado ------\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d\t", sol[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Nao existe um caminho de [0][0] a [N - 1][N - 1]");
	}
	
	return 0;
}

int isSafe(int lbr[MAX][MAX], int n, int i, int j)
{
	if (i >= 0 && i < n && j >= 0 && j < n && lbr[i][j] == 1)
	{
		return 1;
	}
	return 0;
}

int maze(int lbr[MAX][MAX], int n, int i, int j, int sol[MAX][MAX])
{
	if (i == 0 && j == 0)
	{
		sol[i][j] = 1;
		return 1;
	}
	
	if (isSafe(lbr, n, i, j))
	{
		sol[i][j] = 1;
		if (maze(lbr, n, i - 1, j, sol))
		{
			return 1;
		}
		if (maze(lbr, n, i, j - 1, sol))
		{
			return 1;
		}
		sol[i][j] = 0;
		return 0;
	}
	return 0;
}
