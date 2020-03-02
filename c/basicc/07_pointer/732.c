#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5 ,7};     
    int i;
	int n = sizeof(a)/sizeof(a[0]);
    int *p = a;
	for(i = 0; i < n; i++)
	{
		printf("* method %d\n ", *(p+i));
		printf("[] method %d\n ", a[i]);
	}

	for(i = 0; i < n; i++)
	{
		*(p + i) = i;
	}
	for(i = 0; i < n; i++)
	{
		printf("++ method %d\n ", *(p++));
		//printf("* method %d\n ", *(p+i));
		printf("[] method %d\n ", a[i]);
	}
    return 0;
    return 0;
}

