#include <stdio.h>

void fun(int *a)
{
	*a = 20;
}
int main(int argc, char *argv[])
{
    int a = 10;
	printf("a %d\n", a);
	fun(&a);
	printf("a %d\n", a);
    return 0;
}

