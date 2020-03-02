#include <stdio.h>
#include <stdlib.h>

void *fun(int * p)
{
    p = (int *)malloc(sizeof(int));
	*p = 30;
}
int main(void)
{
    int *p = NULL;
	int * q;
	fun(p);
    printf("%d\n", *q);
	return 0;
}

