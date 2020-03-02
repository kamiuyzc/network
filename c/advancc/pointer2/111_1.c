#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate(char **tmp)  
{
    *tmp = (char *)malloc(100 * sizeof(char));
	strcpy(*tmp, "abcde");
}

void my_free(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
}
int main(int argc, char *argv[])
{
    char *p = NULL; 
	allocate(&p);
	printf("%s\n", p);
	printf("%p\n", p);
    my_free(&p);
	printf("%p\n", p);
    return 0;
}

