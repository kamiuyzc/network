#include "hmath.h"

int main(int argc, char *argv[])
{
	int a = 10, b = 5;
    printf("%d %d %d\n", a, b , add(a, b)); 
    printf("%d %d %d\n", a, b , min(a, b)); 
    printf("%d %d %d\n", a, b , mul(a, b)); 
    printf("%d %d %d\n", a, b , dive(a, b)); 
    return 0;
}

