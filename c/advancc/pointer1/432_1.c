#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

void fun(char **p , int *n)
{
	char *tmp = (char *)malloc(10 * sizeof(char));
	if (tmp != NULL)
	{
		strcpy(tmp, "abcdef");
	}
	*p = tmp;
	*n = strlen(*p);
}


int main(int argc, char *argv[])
{
    int n = 0;
	char *p = NULL;
	fun(&p, &n);

	if (p != NULL)
	{
		printf("%d %s\n", n, p);
	}
    return 0;
}

