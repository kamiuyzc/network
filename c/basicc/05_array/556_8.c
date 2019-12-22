#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "My Name Is Yzc!";
	char dst[100];
	strcpy(dst, str1);

	char *p;
	p = strtok(dst, " ");
	while (p != NULL)
	{
		printf("%s\n", p);
		p = strtok(NULL, " ");
	}
}

