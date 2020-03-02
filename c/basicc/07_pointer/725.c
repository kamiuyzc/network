#include <stdio.h>

int main(void)
{
	int a = 10;
    void *p;
	p = &a;

	printf("a is %d", *((int *)p));
    return 0;
}

