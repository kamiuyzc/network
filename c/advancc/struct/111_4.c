#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _TEACHER
{
	char *name;
	int age;
}Teacher;

int main(void)
{
    Teacher p1;
	p1.name = malloc(50);
	strcpy(p1.name, "abcde");
	p1.age = 30;
    Teacher p2;
	p2 = p1;
	printf("%s %d\n",p1.name, p1.age);
	printf("%s %d\n",p2.name, p2.age);
	strcpy(p1.name, "bcde");
	printf("\n");
	printf("%s %d %p\n",p1.name, p1.age, p1.name);
	printf("%s %d %p\n",p2.name, p2.age, p2.name);
	p2.name = malloc(50);
	printf("\n");
	strcpy(p2.name, "qqqbcde");
	printf("%s %d %p\n",p1.name, p1.age, p1.name);
	printf("%s %d %p\n",p2.name, p2.age, p2.name);
	return 0;
}

