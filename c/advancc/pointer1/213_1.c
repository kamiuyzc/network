#include <stdio.h>
int fun(int b)
{
	printf("fun &b %x\n", &b);
}
int main(void)
{
    int c = 0xaabbccdd; 
    int a = 0xaabbccdd; 
	fun(&c);
	printf("&c %x\n", &c);
    unsigned int *p1 = &a;
	unsigned char *p2 = &a;

	printf("p1 %x\n", *p1);
	printf("p2 %x\n", *p2);
	printf("p1 %x\n", p1);
	printf("p1 + 1 %x\n", p1 + 1);
	printf("p2 %x\n", p2);
	printf("p2 + 1 %x\n", p2 + 1);
	return 0;
}

