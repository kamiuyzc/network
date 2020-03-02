#include <stdio.h>

void print_array(int *p, int len);

void print_array(int *p, int len)
{
	int i;
    for(i = 0;i < len; i++)
	{
		printf("%d", *(p+i));
	}
}


int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 10}; 
	int n = sizeof(a) / sizeof(a[0]);
	print_array(a, n);
    return 0;
}

