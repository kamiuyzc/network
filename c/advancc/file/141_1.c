#include <stdio.h>

int my_read()
{
  FILE *fp = fopen("1.txt", "r");  
  char a[10240] = {0};
  int n = fread(a, 1, 10240, fp);
  fclose(fp);
  return n;
}

int main(void)
{
	FILE *fp = fopen("1.txt", "w");
	int n = -1;
	int i = 0;
    while(!(n = my_read()))  
	{
		fputc('a', fp);
	}
	printf("%d\n", n);
    fclose(fp);
	return 0;
}

