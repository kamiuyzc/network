#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int args, char *argv[])
{
	FILE *fp = fopen("1.txt", "w");

	int n = N * 1024 * 1024;
	while(n)
	{
		fputc('a', fp);
		n--;
	}

	fclose(fp);

	return 0;
}

