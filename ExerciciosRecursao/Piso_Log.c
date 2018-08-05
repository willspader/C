#include <stdio.h>

int piso_log (int n);

int main ()
{
	int n = 255;
	printf("%d\n", piso_log (n));
}

int piso_log (int n)
{
	int i = 0;
	if (n/2 == 1) return i+=1;
	i = piso_log (n/2);
	return i+=1;
}
