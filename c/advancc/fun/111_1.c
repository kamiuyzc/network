#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef void F(int, int);
typedef void (*P)(int, int);

void add(int a, int b)
{
	printf("add %d\n", a + b);
}

void min(int a, int b)
{
	printf("min %d\n", a - b);
}

void mul(int a, int b)
{
	printf("mul %d\n", a * b);
}

void dive(int a, int b)
{
	printf("div %d\n", a / b);
}

void test1()
{
	F *f1 = add;
	f1(10, 30);

	P f2 = add;
	f2(30, 40);

	void (*f3)(int, int) = add;
	f3(70, 60);
}

void test2(int a, int b)
{
	void (*f3[4])(int, int) = {add, min, mul, dive};
	int i;
	for(i = 0;i < 4;i++)
	{
		f3[i](a, b);
	}
}

void test3(void (*p)(int, int), int a, int b)
{
	printf("result is:\n");
	p(a, b);
}

int main(int argc, char *argv[])
{
	//test1();
	//test2(30, 5);
	char a[10];
	void (*p[4])(int, int) = {add, min, mul, dive};
	int i;
	for(i = 0;i < 4;i++)
	{
		test3(p[i], 10, 5);
	}
	return 0;
}

