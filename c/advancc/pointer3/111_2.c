#include <stdio.h>

int main(int argc, char *argv[])
{
	typedef int A[10];
	A a = {0};
    A *p = NULL;  	
    
	p = &a;
	for(int i = 0;i < 10;i++)
	{
		(*p)[i] = i * 2 + 1;
	}

	for(int i = 0;i < 10;i++)
	{
		printf("%d\n", (*p)[i]);
	}

}
