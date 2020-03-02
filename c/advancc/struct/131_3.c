#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Teacher
{
	char **stu;
	char *name;
	int age;
}T;

void new_tea(T **p, int n)
{
	T *q = (T *)malloc(sizeof(T) * n);
	int i, j;
	for(i = 0;i < n;i++)
	{
		q[i].name = (char *)malloc(sizeof(char) * 30);
		sprintf(q[i].name, "Teacher %d", i * 2 + 1);
		q[i].age = i%2 * 10 + i;
		q[i].stu = (char **)malloc(sizeof(char *) * 5);
		for(j = 0;j < 5;j++)
		{
			q[i].stu[j] = (char *)malloc(sizeof(char) * 50);
			sprintf(q[i].stu[j], "Tea %d Std %d", i * 2 + 1, j);
		}
	}
	*p = q;
}

void show_tea(T **p, int n)
{
	T *q = *p;
	int i, j;
	for(i = 0;i < n;i++)
	{
		printf("%s age:%d:", q[i].name ,q[i].age);
		q[i].age = i * 10 + 2;
		for(j = 0;j < 5;j++)
		{
			printf("%s ", q[i].stu[j]);
		}
		printf("\n");
	}
}

void sort_tea(T *p, int n)
{
	T tmp;
	int i, j;
	for(i = 0;i < n - 1;i++)
	{
		for(j = i + 1;j < n;j++)
		{
            if(p[i].age > p[j].age) 
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp; 

			}
		}
	}
}
int main(void)
{
	T *p; 
	new_tea(&p, 3);
	show_tea(&p, 3);
	sort_tea(p, 3);
	printf("\n");
	show_tea(&p, 3);
	return 0;
}

