#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myallocate(char **p)
{
	*p = malloc(sizeof(char) * 10);
	strcpy(*p, "abcde");
}

void aamyfree(char **p)
{
    free(*p);
	*p = NULL;
}

int main(int argc, char *argv[])
{
	char *p = NULL;
    myallocate(&p); 

    printf("string is %s\n", p);

	aamyfree(&p);

	if (p == NULL)
	{
        printf("free p\n");
	}

    return 0;
}

