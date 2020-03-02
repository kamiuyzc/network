#include <stdio.h>

int main(void)
{
	const int a = 10;
    int *p; 
	p = &a;
    //a = 20;
	*p = 30;
	printf("%d\n", a);


	return 0;
}

