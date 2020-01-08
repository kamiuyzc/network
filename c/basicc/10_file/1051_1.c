#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	char ch;
	while(!feof(fp))
	{
        printf("%c", fgetc(fp));
	}
	printf("\n");
	fclose(fp);
	return 0;
}

