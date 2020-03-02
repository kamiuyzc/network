#include <stdio.h>

int main(int argc, char *argv[])
{
    typedef int (*P)[10];
	P p1;
    int (*p2)[10];
	int a[10];
	int *p2 = &a;
    return 0;
}

