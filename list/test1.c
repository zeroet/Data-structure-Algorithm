#include <stdio.h>

void swap(int *a, int *b)
{
	*a = 20;
	*b = 200;
}

int main()
{
	int a = 10;
	int b = 100;

	printf("%d - %d\n", a, b);
	swap(&a, &b);
	printf("%d - %d\n", a, b);
	return (0);
}
