#include "hyzc.h"

int main(int args, char *argv[])
{
	unsigned int res, i;
    res = alarm(1); 
	printf("alarm return %d\n", res);
    for(i = 0;;i++)
	{
		printf("%d\n", i++);
	}

	return 0;
}

