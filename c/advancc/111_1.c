#include <stdio.h>
typedef A[10];

int main(int argc, char *argv[])
{
    A b = {0};
	for(int i = 0;i < 10;i++)
	{
		b[i] = i * 3;
	}
	for(int i = 0;i < 10;i++)
	{
		printf("%d\n", *(b+i));
	}
    return 0;
}

