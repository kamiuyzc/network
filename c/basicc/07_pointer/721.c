#include <stdio.h>

int main(void)
{
    int a = 5;
	int b = 10;

	int *p;
    p = &a;

	int *q = &b;
	printf("the pointer %p the value %d\n", p, *p);
	printf("the pointer %p the value %d\n", q, *q);

	*p = 20;
	*q = 30;

	printf("the pointer %p the value %d\n", p, *p);
	printf("the pointer %p the value %d\n", q, *q);

    return 0;
}

