#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5};     
	int *p1 = &a[0];
	int *p2 = &a[1];
	printf("p2 - p1 = %ld\n", p2-p1);
	printf("int p2 - int p1 = %d\n", (int)p2-(int)p1);
    return 0;
}

