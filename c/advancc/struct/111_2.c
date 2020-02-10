#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persion
{
	char name[64];
	int age;
};
int main(void)
{
    struct Persion p1 = {"abc", 20};    
	printf("%s %d\n", p1.name, p1.age);

    struct Persion *p2 = (struct Persion *)malloc(sizeof(struct Persion));
	strcpy(p2->name, "edfg");
	p2 -> age = 30;
	printf("%s %d\n", p2 -> name, p2 ->age);
	return 0;
}

