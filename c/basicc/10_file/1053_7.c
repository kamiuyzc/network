#include <stdio.h>

void read_file()
{
	FILE *fp = fopen("1.out", "r");
	char a[100] = {0};
	fread(a, 1, sizeof(a), fp);
	printf("%s", a);
	fclose(fp);
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "w"); 
	fputs("abcde", fp);
	printf("before\n");
	read_file();
	fflush(fp);
	printf("after\n");
	read_file();
    return 0;
}

