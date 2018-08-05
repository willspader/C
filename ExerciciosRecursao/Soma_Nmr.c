#include <stdio.h>

int soma_nmr(int n);

int main()
{	
	int n = 364;
	printf("%d\n", soma_nmr(n));
}

int soma_nmr(int n)
{	
	if (n/10 == 0) return n%10;
	return n%10 + soma_nmr(n/10);
}
