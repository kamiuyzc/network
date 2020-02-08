#include <stdio.h>

int main(int argc, char *argv[])
{
    int (*p)[10];
    int a[10] = {0};
	p = &a;
	int i;
	for(i = 0;i < 10;i++)
	{
		*(*p + i) = i * 2 - 1;
	}
	for(i = 0;i < 10;i++)
	{
		printf("%d\n", (*p)[i]);
	}
    return 0;
}

