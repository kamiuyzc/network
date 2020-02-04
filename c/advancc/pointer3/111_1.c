#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("para num is %d\n", argc);
	int i;
	for(i = 0;i < argc;i++)
	{
		printf("%s\n", argv[i]);
	}

	char *a[] = {"abc", "def", "ghi"};
	for(i = 0;i < sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%s\n", a[i]);
	}
}
