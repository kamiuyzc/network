#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getsum(char *p);

int getsum(char *p)
{
	int result = 0;
	int n;
	p = strtok(p, ",");

	while (p != NULL)
	{
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

