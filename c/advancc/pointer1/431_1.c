#include <stdio.h>
#include <string.h>

void fun(char *a)
{
    strcpy(a, "abcde");
}

int main(int argc, char *argv[])
{
    char a[10] = {0};
	fun(a);
	printf("%s\n", a);
    return 0;
}

