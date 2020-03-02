#include <stdio.h>

int main(void)
{
    int *p1;
	char *p2;
	int **p3;
	printf("p1 %ld\n", sizeof(p1));
	printf("p2 %ld\n", sizeof(p2));
	printf("p3 %ld\n", sizeof(p3));
	printf("p3 %ld\n", sizeof(double *));
}

