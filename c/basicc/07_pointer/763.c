#include <stdio.h>
int N = 10;

int *getn();

int *getn()
{
	return &N;
}
int main(int argc, char *argv[])
{
    int *r = getn(); 
	*r = 20;
	printf("%d\n", N);
    return 0;
}

