#include <stdio.h>

int main(int argc, char *argv[])
{
	char *c1 = "abc\012def";
	char *c2 = "abc\x0c";
    printf("*8 %s\n*", c1); 
    printf("$16 %s\n$", c1); 

    return 0;
}

