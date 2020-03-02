#include <stdio.h>

int main(int argc, char *argv[])
{
    int b;
	int *p1 = &b;
	int **p2 = &p1;
	int ***p3 = &p2;
	printf("p1 %p\n", p1);
	printf("p2 %p\n", p2);
	printf("p3 %p\n", p3);
    return 0;
}

