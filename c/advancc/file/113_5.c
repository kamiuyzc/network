#include <stdio.h>
#include <string.h>

void my_fput(char *path)
{
	FILE *fp = fopen(path, "w");
	char baf[] = "aa\n";
	int len = strlen(baf);
	char ch;
	for(int i = 0;i < len;i++)
	{
		ch = fputc(baf[i], fp);
		//printf("%c", ch);
	}
	fclose(fp);
}

void my_fget(char *path)
{
	char ch;
	FILE *fp = fopen(path, "r");
	printf("start print1\n");
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);	
	}
	printf("end print1\n");
	fclose(fp);
}

void my_fget2(char *path)
{
	char ch;
	FILE *fp = fopen(path, "r");
	printf("start print2\n");
	while(!feof(fp))
	{
		ch = fgetc(fp);
		if(ch != EOF)
		{
			printf("%c", ch);	
		}
	}
	printf("end print2\n");
	fclose(fp);
}

int main(void)
{
	char *path = "2.txt";
	my_fput(path); 
	my_fget(path); 
	my_fget2(path); 
	return 0;
}

