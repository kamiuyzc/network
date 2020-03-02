#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *p;
	char *q;
	int l = 8;
    p = (int *)malloc(l);
	q = (char*)p;
    memset(p, 65, l);
	for (int i = 0;i < l; i++)
	{
		if(i % 2 == 0)
		{
			q[i] = 99;
		}
	}
	for (int i = 0;i < 2; i++)
	{
		printf("%p\n", (p + i));
		printf("%x\n", *(p + i));
	}
	printf("lala\n");
	for (int i = 0;i < l; i++)
	{
		printf("%p\n", (q + i));
		printf("%x\n", *(q + i));
	}
	free(p);
	free(q);
	return 0;
}

