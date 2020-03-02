#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5, 10};     
	printf("a = %p\n", a);
	printf("&a[0] = %p\n", &a[0]);
    return 0;
}

