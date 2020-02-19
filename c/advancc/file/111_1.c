#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
	if((fp = fopen("1.txt", "r")) == NULL)
	{
		perror("error no");
	}
	else
	{
		printf("open success");
		fclose(fp);
	}
	return 0;
}

