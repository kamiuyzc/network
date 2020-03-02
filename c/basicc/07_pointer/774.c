#include <stdio.h>

int main(int argc, char * argv[])
{
	printf("argc = %d\n", argc);
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		printf("%d para is %s\n", i, argv[i]);
	}
    return 0;
}

