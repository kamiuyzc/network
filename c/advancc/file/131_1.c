#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("121_1.c", "r"); 
	fseek(fp, 0, SEEK_END);
	int n = ftell(fp);
	rewind(fp);
	char a[1024] = {0};
	fread(a, n, 1, fp);
	printf("%s", a);
	fclose(fp);
	return 0;
}

                                   