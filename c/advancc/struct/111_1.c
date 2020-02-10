#include <stdio.h>
#include <string.h>
struct Persion
{
	char name[64];
	int age;
};

typedef struct _Persion1
{
	char name[64];
	int age;
}Persion2;

int main(void)
{
    struct Persion p;
	p.age = 20;
	strcpy(p.name, "abcde");
	
	Persion2 q;
	q.age = 30;
	strcpy(q.name, "lalala");
	printf("%s %d\n",p.name, p.age);
	printf("%s %d\n",q.name, q.age);
	return 0;
}

