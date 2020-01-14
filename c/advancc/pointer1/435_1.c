#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fun(char *a, char *b, int *n)
{
    char *start;
	start = a;
	int len = strlen(start);
	char *end = start + len - 1;
	while(isspace(*start))
	{
        start++;
	}
	while(isspace(*end))
	{
        end--;
	}

	*n = end - start + 1;
	strncpy(b, start, *n);
    *(start + *n) = '\0';
}

int main(int argc, char *argv[])
{
    char a[100] = "   hello   ";
	char b[20] = {65};
	int n = 0;
	fun(a, b, &n);
	printf("%s %d", b, n);
    return 0;
}

