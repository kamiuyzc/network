#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
	char name[50];
	int age;
};
int main(void)
{
    struct stu *p;
	p = (struct stu *)malloc(sizeof(struct stu));
    strcpy(p->name, "yzc");
	p->age = 20;
	printf("%s %d\n", p->name, p->age);
	free(p);
	p = NULL;
	return 0;
}

