#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Teacher
{
	char *name;
	int age;
};
void getmem(struct Teacher **p, int n)
{
	struct Teacher *q = (struct Teacher *)malloc(3 * sizeof(struct Teacher) * 3);
	*p = q;
	int i;
	for(i = 0;i < n;i++)
	{
		q[i].name = (char *)malloc(sizeof(char) * 10);
		sprintf(q[i].name, "student %d", i * 2 + 1);
	    q[i].age = i * 10 + 1;
	}
}

void print_mem(struct Teacher **p, int n)
{
	int i;
	struct Teacher *q = *p;
	for(i = 0;i < n;i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}
}

void free_mem(struct Teacher **p, int n)
{
	struct Teacher *tmp = *p;
	int i;
	for(i = 0;i < n;i++)
	{
		if(tmp[i].name != NULL)
		{
			free(tmp[i].name);
			tmp[i].name = NULL;
		}
	}
	free(tmp);
	tmp = NULL;
}
int main(void)
{
	struct Teacher *q;
	getmem(&q, 3);
	print_mem(&q, 3);
	free_mem(&q, 3);
	return 0;
}
 
