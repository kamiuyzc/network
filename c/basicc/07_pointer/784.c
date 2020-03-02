#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1;
	int *p1 = &a;
    int **p2 = &p1;

	printf("a = %d\n", a);
	printf("*p1 = %d\n", *p1);
	printf("**p2 = %d\n", **p2);

	char *a[] = "fuck you!";
	char **pp1 = &a;

    return 0;
}

