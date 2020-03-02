#include <stdio.h>
#include <string.h>

void myputs(char *path)
{
    char *a[10] = {"abc\n", "1\n", "ffaa\n", "\n", "\n"};
	FILE *fp = fopen(path, "w");
	int n;
	for(int i = 0;i < 5;i++)
	{
	    n = fputs(a[i], fp);	
		//printf("%d\n", n);
	}
	fclose(fp);
}

void mygets(char *path)
{
	FILE *fp = fopen(path, "r");
	char a[30], c[30];
	char *b;
    b = c;
    while(!feof(fp))
	{
       b = fgets(a, 50, fp);
	   if(b != NULL && b[0] != '\n')
	   {
	       printf("a:%s", a);
	   }
	}
	fclose(fp);
}
int main(void)
{
	char *path = "3.txt";
    myputs(path); 
	mygets(path);
	return 0;
}

