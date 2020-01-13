#include <stdio.h>
#include <stdlib.h>

void fun(int **p)
{
	*p = (int *)malloc(sizeof(int));
}

void fun2(int **p3)
{
    free(*p3);	
	*p3 = NULL;
}

int main(int argc, char *argv[])
{
    int *p1 = NULL;
    int **p2 = &p1;
	fun(p2);
	*p1 = 30;
	printf("%d\n", *p1);
	fun2(p2);
	//printf("%d\n", *p1);
	if (p1 == NULL)
	{
		printf("free p");
	}
    return 0;
}

