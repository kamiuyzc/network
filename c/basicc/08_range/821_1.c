#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int *p = NULL;
	p =(int *)malloc(sizeof(int));
    *p = 20;
	printf("%d\n", *p);
	return 0;
	if (p != NULL)
	{
		free(p);
	}
}

