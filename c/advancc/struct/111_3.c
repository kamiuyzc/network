#include <stdio.h>
struct Persion
{
	char name[10];
	int age;
};
int main(void)
{
    struct Persion p1 = {"abc", 20};
    struct Persion p2 = {"def", 30};
	printf("%s %d\n", p1.name, p1.age);
	printf("%s %d\n", p2.name, p2.age);
    p1 = p2;
	printf("%s %d\n", p1.name, p1.age);
	printf("%s %d\n", p2.name, p2.age);
	return 0;
}

