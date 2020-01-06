#include <stdio.h>
#include <string.h>
struct stu
{
	int num;
	char a[10];
};

void fun3(struct stu *tmp, int n)
{
	for (int i = 0; i < n; i++)
	{
		tmp->num = i * 10;
		strcpy(tmp->a, "abc");
		tmp++;
	}
}
void fun4(struct stu const * const tmp, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", (tmp + i)->num, (tmp + i)->a);
	}
}
int main(int argc, char *argv[])
{
	struct stu a[3]; 
	int n = sizeof(a)/sizeof(a[0]);
	fun3(a, n);
	fun4(a, n);
	return 0;
}

