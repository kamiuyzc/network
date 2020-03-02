#include <stdio.h>

int main(int argc, char *argv[])
{
    char a[][10] = {"abcdde", "ghiji", "lala"};

	printf("a length %p %p\n", a, a+1);
	printf("&a length %p %p\n", &a, &a+1);
	printf("a[0] length %p %p\n", a[0], a[0]+1);
	printf("a[0][0] length %p %p\n", a[0][0], a[0][0]+1);
    return 0;
}

