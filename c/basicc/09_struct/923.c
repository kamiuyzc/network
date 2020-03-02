#include <stdio.h>

typedef unsigned int UINT;
struct student
{
	UINT a;
};
typedef struct student STU;
typedef struct student *PSTU;
int main(int argc, char *argv[])
{
    UINT a = 10;
	STU s1 = {50};
    PSTU p;
	p = &s1;
	printf("%d %d\n", a, s1.a);
	p->a = 60;
	printf("%d %d\n", a, s1.a);
    return 0;
}

