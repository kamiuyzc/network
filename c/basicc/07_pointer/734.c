#include <stdio.h>

int main(int argc, char *argv[])
{
    int *a[3];
    int c = 1;
	int b = 3;
	a[0] = &c;
	a[1] = &b;
	printf("result is %d", *a[0]);
    return 0;
}

