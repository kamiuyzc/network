#include <stdio.h>
#include <string.h>

void print_array(char a[][30], int n)
{
	for(int i = 0;i < n;i++)
	{
		printf("%s\n", a[i]);
	}
}

void sort_array(char a[][30], int n)
{
    char tmp[30];
	int i, j;
	for(i = 0;i < n - 1;i++)
	{
		for(j = 0;j < n - 1 - i;j++)
		{
			if(strcmp(a[j], a[j + 1]) > 0)
			{
				strcpy(tmp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], tmp);

			}
		}
	}
}

int main(int argc, char *argv[])
{
    char a[][30] = {"abcde", "eghijk", "bcdef"};
    int len = sizeof(a) / sizeof(a[0]);
    print_array(a, len);
	sort_array(a, len);
    print_array(a, len);
    return 0;
    return 0;
}

