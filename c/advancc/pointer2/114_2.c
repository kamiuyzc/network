#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

void print_array(char **p, int len)
{
	for(int i = 0;i < len;i++)
	{
		printf("%s\n", p[i]);
	}
}

void sort_array(char **p, int len)
{
	int i = 0;
	int j = 0;
	char *tmp = NULL;
	for(i = 0;i < len - 1;i++)
	{
		for(j = 0;j < len - 1 - i;j++)
		{
			if (strcmp(p[j], p[j + 1]) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
char **allocate(void)
{
	char **p;
	srand((unsigned int)time(NULL));
	p = (char **)malloc(N * sizeof(char *));
	int i = 0;
	char tmp[20] = {0};
	for(i = 0;i < N;i++)
	{
		p[i] = (char *)malloc(20 * sizeof(char));
		memset(tmp, 0, 20);
		sprintf(tmp, "value is %d", rand()%100);
		strcpy(p[i], tmp);
	}
	return p;
	
}

void my_free(char **p, int len)
{
    for(int i = 0;i < len;i++)
	{
        free(p[i]);
	}
	free(p);
}
int main(int argc, char *argv[])
{
	char **p = NULL;
	p = allocate();
    print_array(p, N);
	printf("\n");
	sort_array(p, N);
	print_array(p, N);
    p = NULL;
	return 0;
}

