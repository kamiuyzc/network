#include <stdio.h>
#include <stdlib.h>

void *fun(int * p)
{
	*p = 30;
}
int main(void)
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int));
	fun(p);
    printf("%d\n", *p);
	return 0;
}

