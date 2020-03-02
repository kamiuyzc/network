#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Teacher
{
	char *name;
	int age;
};
int main(void)
{
    struct Teacher t;
    t.name = (char *)malloc(sizeof(char) * 10);
	strcpy(t.name, "abcde");
	t.age = 30;
	printf("%s %d\n", t.name, t.age);

	struct Teacher *p;
	p = (struct Teacher *)malloc(sizeof(struct Teacher));
	p -> name = (char *)malloc(sizeof(char) * 10);
	strcpy(p -> name, "edcba");
	p -> age = 20;
	printf("%s %d\n", p -> name, p -> age);
	free(p -> name);
	p -> name = NULL;
	free(p);
	p = NULL;

	struct Teacher *q;
	q = (struct Teacher *)malloc(3 * sizeof(struct Teacher) * 3);
	int i;
	for(i = 0;i < 3;i++)
	{
		q[i].name = (char *)malloc(sizeof(char) * 10);
		sprintf(q[i].name, "student %d", i * 2 + 1);
	    q[i].age = i * 10 + 1;
	}
	for(i = 0;i < 3;i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}
	return 0;
}
 
