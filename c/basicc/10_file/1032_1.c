#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "w"); 
	char *str[] = {"abcde\n", "lalala\n", "333333333"}; 
	int ret;
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		ret = fputs(str[i], fp);
		printf("%d", ret);
	}
	fclose(fp);
    return 0;
}

