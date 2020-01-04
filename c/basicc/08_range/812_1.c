#include <stdio.h>
void fun1(void);
void fun2(void);

void fun1(void)
{
	int i = 0;
	printf("fun1 i is %d\n", ++i);
}

void fun2(void)
{
	static int i = 0;
	printf("fun2 i is %d\n", ++i);
}

int main(void)
{
    fun1();
    fun1();
    fun2();
    fun2();
	return 0;
}

