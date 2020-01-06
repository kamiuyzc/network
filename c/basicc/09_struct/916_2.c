#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
	char *name;
	int age;
};

int main(void)
{
    struct stu *s1 = malloc(sizeof(struct stu));
	s1->name = malloc(strlen("test")+1);
    strcpy(s1->name, "test");	
    s1->age = 50;
	printf("%s %d\n", s1->name, s1->age);
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

