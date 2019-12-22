#include <stdio.h>

int main(void)
{
    int * const p;
	int a = 10;
	int b = 20;
	p = &a;
	printf("*p is %d\n", *p);
	p = &b;
	printf("*p is %d\n", *p);
	*p = 30;
    return 0;
}

