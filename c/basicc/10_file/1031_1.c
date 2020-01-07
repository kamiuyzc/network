#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *fp;
	fp = fopen("1.out", "w");
    char *a;
    int size = 20 * sizeof(char);
    a = (char *)malloc(size);
	memset(a, 0, size);
	a = "test is us!";
	int len = strlen(a);
	//printf("str len %d\n", len);
	for(int i = 0; i < len; i++)
	{
		int ch = fputc(*(a++), fp);
		printf("%d\n", ch);
	}
    return 0;
}

