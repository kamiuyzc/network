#include <stdio.h>
typedef struct _Student
{
	char name[50];
	int age;
}Student;

int main(void)
{
    Student a[] = {"aa", 1, "bb", 3, "cc", 5};
	for(int i = 0;i < 3;i++)
	{
		printf("%s %d\n", a[i].name, a[i].age);
	}
	return 0;
}

