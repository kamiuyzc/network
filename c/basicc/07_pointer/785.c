#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char a[] = "      0123456789      "; 
	char *start = a;
	char *end = a + sizeof(a) - 1;

	while (*start == ' ')
	{
		start++;
	}

	while (*end == ' ' || *end == '\0')
	{
		end--;
	}

	char buf[100];
	int n = end - start + 1;
	strncpy(buf, start, n);
	*(buf + n) = '\0';
	printf("result is $%s$\n", buf);


    return 0;
}

