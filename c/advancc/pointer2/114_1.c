#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a = (int *)malloc(sizeof(int) * 10);
	for(int i = 0;i < 10;i++)
	{
		a[i] = 10 * i;
	}
	
	for(int i = 0;i < 10;i++)
	{
		printf("%d\n", a[i]);
	}
    return 0;
}

