#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 5}; 
	int *p[3];

	int n = sizeof(p) / sizeof(*p);
    int i = 0;
	for(i = 0; i < n;i++)
	{
		p[i] = &a[i];
	}

	for(i = 0; i < n;i++)
	{
		printf("%d\n", *p[i]);
	}
    return 0;
}

