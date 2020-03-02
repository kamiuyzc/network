#include <stdio.h>

int main(void)
{
	char buf[] = "hello world\n";
    FILE *fp = fopen("1.txt", "w");    
	fputs(buf, fp);
	fflush(fp);
	fclose(fp);
	return 0;
}

