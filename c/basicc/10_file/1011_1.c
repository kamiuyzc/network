#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
	fp = fopen("2.out", "r");
	if (fp == NULL)
	{
		perror("open");
		return 1;
	}
	EOF
	printf("%d\n",fp->_fileno);
    fclose(fp);	
    return 0;
}

