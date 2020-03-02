#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
	char *name;
	int age;
	char *company;
	char *contry;
};

int main(void)
{
    struct stu *s1 = malloc(sizeof(struct stu));
	s1->name = malloc(strlen("test")+1);
	s1->company = "neusoft";
	char a[10];
	s1->contry = a;
	strcpy(s1->contry, "china");
    strcpy(s1->name, "test");	
    s1->age = 50;
	printf("%s %s %s %d\n", s1->name, s1->company, s1->contry, s1->age);
	if (s1->name != NULL)
	{
        free(s1->name);
		printf("free s1->name\n");
	}
	if (s1 != NULL)
	{
        free(s1);
		printf("free s1\n");
	}
	return 0;
}

