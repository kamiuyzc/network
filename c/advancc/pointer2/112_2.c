#include <stdio.h>
#include <string.h>

void print_array(char **a, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%s\n", a[i]);
	}
}

void sort_array(char **a, int n)
{
	int i = 0;
	int j = 0;
	char *p;
	for(i = 0;i < n - 1;i++)
		for(j = i + 1;j < n;j++)
		{
            if (strcmp(a[i], a[j]) > 0) 
			{
				p = a[i];
			    a[i] = a[j];
				a[j] = p;
			}
		}
}

int main(int argc, char *argv[])
{
    char *a[3] = {"oabcde", "ghijk", "lalala"};
	int len = sizeof(a) / sizeof(a[0]);
    print_array(a, len);
	sort_array(a, len);
	printf("******aftef\n");
    print_array(a, len);

    return 0;
}

