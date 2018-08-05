#include <stdio.h>

int main ()
{	
	int n = 4, v[4] = {-2, 7, -3, 5};
	printf("%d\n", soma_pos (n, v));
}

int soma_pos (int n, int v[])
{
	if (n == 1) {
		if (v[n - 1] > 0) return v[n - 1];
		else return 0;
	} else {
		if (v[n - 1] > 0) return v[n - 1] + soma_pos(n - 1, v);
		else soma_pos(n - 1, v);
	}
}
