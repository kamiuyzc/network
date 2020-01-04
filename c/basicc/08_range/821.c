#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int *p;
    p = (int *)malloc(sizeof(int) * 10);
	
	memset(p, 65 , sizeof(int)*10);
	
	return 0;
}

