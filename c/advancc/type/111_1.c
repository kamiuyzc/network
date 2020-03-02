#include <stdio.h>

int main(void)
{
    int a[10] = {};
	printf("&a %p &a++ %p\n", &a, (&a) + 1);
	printf("a %p a++ %p\n", a, a + 1);
	return 0;
}

