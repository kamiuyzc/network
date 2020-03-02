#include <stdio.h>

int main(void)
{
    char *a = "abcde"; 
	char b[] = "eghij";

    //a[1] = 'm'; error
    b[1] = 'm';
    printf("a %s\n", a);
    printf("b %s\n", b);
	return 0;
}

