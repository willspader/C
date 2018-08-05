#include <stdio.h>

int expo (int k, int n);

int main ()
{
	int k = 2, n = 3;
	printf("%d\n", expo(2, 3));
}

int expo (int k, int n)
{
	if (n <= 1) return k;
	else return k * expo (k, n-1);
}
