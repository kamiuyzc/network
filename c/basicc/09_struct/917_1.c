#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	int num;
	char name[10];
};

void fun1(struct stu tmp);

void fun1(struct stu tmp)
{
    tmp.num = 20;
    strcpy(tmp.name, "yzc");
    printf("fun1 %d  %s\n", tmp.num, tmp.name);
}

void fun2(struct stu *p)
{
    p->num = 20;
    strcpy(p->name, "yzc");
}

int main(int argc, char *argv[])
{
	struct stu s1 = {10, "abc"};
    fun1(s1); 
	printf("main %d  %s\n", s1.num, s1.name);
    fun2(&s1); 
	printf("main %d  %s\n", s1.num, s1.name);
    return 0;
}

