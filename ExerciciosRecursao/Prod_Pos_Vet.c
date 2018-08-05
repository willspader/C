#include <stdio.h>

int prod_pos(int n, int v[]);

int main()
{
	int n = 4, v[4] = {4, -7, 5, 3};
	printf("%d\n", prod_pos(n, v));
}

int prod_pos(int n, int v[])
{	
	int x = 1;
	if (n == 1) {
		if (v[n - 1] > 0) x *= v[n - 1];
		return x;
	}
	x = prod_pos(n - 1, v);
	if (v[n - 1] > 0) x *= v[n - 1];
	return x;
}
