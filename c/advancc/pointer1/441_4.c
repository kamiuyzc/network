#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1;
	int b = 2;
	int c;
	while ((b = a) == 1)
	{
		printf("ok");
		break;
	}

	while('\x00')
	{
		printf("hi");
	    break;	
	}
    return 0;
}

