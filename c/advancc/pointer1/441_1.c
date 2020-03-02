#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char a[] = {'a', 'b', 'c'};
	printf("a =  %s\n", a);

    char b[4] = {'a', 'b', 'c'};
	printf("b =  %s\n", b);

    char c[] = "hello";
	printf("c =  %s sizeof %d strlen %d\n", c, sizeof(c), strlen(c));

    char d[100] = "hello";
	printf("d =  %s sizeof %d strlen %d\n", d, sizeof(d), strlen(d));

    char e[] = "h\0ello";
	printf("e =  %s sizeof %d strlen %d\n", e, sizeof(e), strlen(e));

    char g[] = "h\012ello";
	printf("g =  %s sizeof %d strlen %d\n", g, sizeof(g), strlen(g));

    return 0;
}

