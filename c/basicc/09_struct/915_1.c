#include <stdio.h>
#include <string.h>
struct Info
{
	char name[10];
	int age;
};

struct student
{
	int num;
	struct Info info;
};
int main(void)
{
    struct student std1;
	std1.num = 10;
	strcpy(std1.info.name, "yzc");
	std1.info.age = 20;
    struct student std2;
    struct student *p;
	p = &std2;
    p->num = 2;
	strcpy(p->info.name, "puyol");
	p->info.age = 30;
    
	struct student std3 = std2;
	printf("%d %s %d \n", std1.num, std1.info.name, std1.info.age);
	printf("%d %s %d \n", std3.num, std3.info.name, std3.info.age);
	printf("%d %s %d \n", p->num, p->info.name, p->info.age);
	return 0;
}

