#include <stdio.h>
int *fun(void);

int *fun(void)
{
	static int a = 10;
	return &a;

}
int main(void)
{
    int *b;
	b = fun();
    *b = 100;	
	printf("%d\n", *b);
	return 0;
}

