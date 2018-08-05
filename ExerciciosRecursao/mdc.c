#include <stdio.h>

int mdc (int m, int n);

int main ()
{
	int m = 90, n = 36;
	printf("%d\n", mdc(m, n));
}

int mdc (int m, int n)
{
	int x;
	x = m % n;
	if (x == 0) return n; 
	return mdc (n, x);
}
