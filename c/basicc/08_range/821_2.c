#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *p;
    int size = sizeof(int) * 10;
	p = (int *)malloc(size);
    memset(p, 0, size);
    for(int i = 0; i < 10; i++)
	{
		p[i] = i * 10;
	}
    for(int i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));
	}
	if (p != NULL)
	{
		free(p);
		printf("free p\n");
	}
	return 0;
}

