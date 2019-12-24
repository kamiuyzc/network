#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5 ,10};
	int *p = a;
	int i = 0;
	int n = sizeof(a) / sizeof(a[0]);
	p = p + n - 1; 
	for(i = 0;i < n;i++)
	{
		printf("*p-- is %d\n", *p--);
	}
    return 0;
}

