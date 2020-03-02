#include <stdio.h>
#include <string.h>

void myputs(char *path)
{
	FILE *fp = fopen(path, "w");
	int n;
	fprintf(fp, "my age is %d", 33);
	fclose(fp);
}

void mygets(char *path)
{
	FILE *fp = fopen(path, "r");
	int age = 0;
	fscanf(fp, "my age is %d", &age);
	printf("result is %d", age);
	fclose(fp);
}
int main(void)
{
	char *path = "3.txt";
    myputs(path); 
	mygets(path);
	return 0;
}

