#include <stdio.h>
int *fun(void);

int *fun(void)
{
	int a = 10;
	return &a;

}
int main(void)
{
    int *b;
	b = fun();
    *b = 100;	
	return 0;
}

