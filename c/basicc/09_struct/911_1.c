#include <stdio.h>
struct student
{
	int num;
	char sex;
	float score;
};

int main(void)
{
    struct student st1 = {1, 'b', 60};
	struct student *p1;
    p1 = &st1;	
	printf("%d %c %f\n", st1.num, st1.sex, st1.score);
	printf("%d %c %f\n", p1->num, p1->sex, p1->score);
    printf("%d %c %f\n", (&st1)->num, (&st1)->sex, (&st1)->score);
    printf("%d %c %f\n", (*p1).num, (*p1).sex, (*p1).score);
	return 0;
}

