#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_sort(char **array1, int num1, char (*array2)[30], int num2, char ***myp3, int *num3)
{
	int lensum = num1 + num2;
    char **tmp = (char **)malloc(sizeof(char *) * lensum);
	*myp3 = tmp;
	char **ptmp;
	ptmp = tmp;
	char *p, *q;
	int i, j;
	for(i = 0;i < num1;i++)
	{
	    q = (char *)malloc(30);
	    strcpy(q, array1[i]);
		*tmp = q;
		tmp++;
	}
	for(i = 0;i < num1;i++)
	{
	    q = (char *)malloc(30);
	    strcpy(q, *(array2 + i));
		*tmp = q;
		tmp++;
	}
	*num3 = lensum;
	char *tt;
	for(i = 0;i < lensum - 1;i++)
	{
		for(j = i;j < lensum - 1;j++)
		{
			if(strcmp(ptmp[j], ptmp[j + 1]) < 0)
			{
			    strcpy(tt, ptmp[j]);
			    strcpy(ptmp[j], ptmp[j + 1]);
			    strcpy(ptmp[j + 1], tt);
			}
		}
	}
}

void my_print(char **array1, int num1)
{
    for(int i = 0;i < num1;i++)
	{
		printf("%s\n", array1[i]);
	}
}

int main(int argc, char *argv[])
{   
    int ret = 0; 
    char *p1[] = {"aaa", "cccccc", "bbbbb"};
    char buf2[10][30] = {"1111", "3333", "2222"};
    char **p3 = NULL;
    int len1, len2, len3, i = 0;
    len1 = sizeof(p1) / sizeof(*p1);
    len2 = 3;
    my_sort(p1, len1, buf2, len2, &p3, &len3);
	my_print(p3, len3);
    return 0;
}
