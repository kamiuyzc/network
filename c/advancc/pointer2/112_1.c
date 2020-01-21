#include <stdio.h>

int main(int argc, char *argv[])
{
    char *a[3] = {"abcde", "ghijk", "lalala"};

	int len = sizeof(a) / sizeof(a[0]);
	for(int i = 0; i < len; i++)
	{
		printf("%s\n", a[i]);
	}
    return 0;
}

