#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getsum(char *p);

int getsum(char *p)
{
	int result = 0;
	int n;
	int j = 0;
	int i = 0;
	char *p1 = p;
	p = strtok(p, ",");

	while (p != NULL)
	{
		for(i = 0;i < 14;i++)
		{
			printf("%c",p1[i]);
		}
		printf(" %s, %d, %p\n",p, j++, p);
		result = result + atoi(p);
		p = strtok(NULL, ",");
	}
	return result;
}

int main(int argc, char *argv[])
{
	char a[100] = "10,20,30,40,50";
	int sum = getsum(a);
	printf("sum = %d\n", sum);
	return 0;
}

