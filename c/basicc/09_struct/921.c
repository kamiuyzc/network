#include <stdio.h>
union test
{
	unsigned short s;
	char c;
	unsigned int i;
};

int main(int argc, char *argv[])
{
    union test t;
	t.i = 0x11223344;
	t.s = 0x55;
	printf("c = %x, s = %x, i = %x\n", t.c , t.s, t.i);
	printf("c = %p, s = %p, i = %p\n", &t.c , &t.s, &t.i);
    return 0;
}

