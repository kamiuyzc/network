#include <stdio.h>

int main(int argc, char *argv[])
{
    typedef int (*A)[10];
	A p = NULL;
	int a[10] = {0};
	p = &a;
	int i = 0;
	for(i = 0;i < 10;i++)
	{
        *((*p) + i) = i * 3 + 1;
	}
	for(i = 0;i < 10;i++)
	{
        printf("%d\n", *((*p) + i));
	}
    return 0;
}

