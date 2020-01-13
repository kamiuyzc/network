#include <stdio.h>

int main(void)
{
    int *p = NULL;
	int a = 10;
	p = &a;
	printf("a address %p\n", &a);
	printf("p address %p\n", p);
	printf("&p address %p\n", &p);
	return 0;
}

