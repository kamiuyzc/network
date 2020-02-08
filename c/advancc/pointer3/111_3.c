#include <stdio.h>

int main(int argc, char *argv[])
{
    typedef int A[10];
	A a;
	A *p;
	p = &a;
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		a[i] = i * 2 + 1;
	}
	for(i = 0;i < 10;i++)
	{
		printf("%d\n", *((*p) + i));
	}
    return 0;
}

