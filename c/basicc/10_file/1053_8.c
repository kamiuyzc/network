#include <stdio.h>
#include <stdlib.h>
int f_read()
{
	FILE *fp = fopen("1.out", "r"); 
	int tmp = fgetc(fp);
	fclose(fp);
	return tmp;
}
int main(int argc, char *argv[])
{
	FILE *fp = fopen("1.out", "w"); 
	while(f_read() == -1)
	{
		fputc(65 + 32, fp);
		//fclose(fp);
	}
	fclose(fp);
}
