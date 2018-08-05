#include <stdio.h>

int potencia (int k, int n);

int main ()
{
	int k = 4, n = 3;
	printf("%d\n", potencia(k, n));
}

int potencia (int k, int n)
{
	if (n == 1) return k;
	return k * potencia(k, n-1);
}
