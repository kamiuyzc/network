#include <stdio.h>
#include <stdlib.h>

int *fun(void)
{
    int *p = (int *)malloc(sizeof(int));
	return p;
}
int main(void)
{
    int *p = NULL;
	p = fun();
	*p = 30;
    printf("%d\n", *p);
	return 0;
}

