#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Teacher
{
	char name[50];
	int age;
};

int main(void)
{
    int a[3] = {0};
	int *p = (int *)malloc(sizeof(int) * 3);
	memset(p, 0, sizeof(int) * 3);
	int i;
	for(i = 0;i < 3;i++)
	{
		*(p + i) = 2 * i + 1;
	}
	for(i = 0;i < 3;i++)
	{
		printf("%d\n", *(p + i));
	}
    
	struct Teacher * q = (struct Teacher *)malloc(sizeof(struct Teacher) * 3);
	memset(q, 0, sizeof(struct Teacher) * 3);
	for(i = 0;i < 3;i++)
	{
		sprintf(q[i].name, "Teacher %d", i * 2 + 1 );
		q[i].age = i * 10 + 1;
	}
	for(i = 0;i < 3;i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}
	
	return 0;
}

