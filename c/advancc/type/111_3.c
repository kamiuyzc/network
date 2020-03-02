#include <stdio.h>
#include <stdlib.h>

void fun(char **p)
{
	*p = "efgh";
}

int main(int argc, char *argv[])
{
    char *p = "abcd";
    char *q = "efgh";

	printf("p = %p %s\n", p,p);
	printf("q = %p %s\n", q,q);
    
	fun(&p);
	printf("p = %p %s\n", p,p);
	printf("q = %p %s\n", q,q);
    
    return 0;
}

