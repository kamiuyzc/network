#include <stdio.h>
#include <string.h>

typedef struct _Teacher
{
    char name[50];
	int age;
}Teacher;

void copy_struct(Teacher *dst, Teacher *src)
{
   *dst = *src; 
}

int main(void)
{
    Teacher t1 = {"abc", 30}; 
	Teacher t2;
	memset(&t2, 0, sizeof(Teacher));
	copy_struct(&t2, &t1);
	printf("%s %d\n", t1.name, t1.age);
	printf("%s %d\n", t2.name, t2.age);
	return 0;
}

