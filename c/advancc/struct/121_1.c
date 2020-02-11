#include <stdio.h>
struct Teacher
{
	int age;
};

int main(void)
{
    struct Teacher t = {30};
	struct Teacher *p = &t;
	printf("%d\n", p -> age);
	return 0;
}

