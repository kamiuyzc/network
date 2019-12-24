#include <stdio.h>

int swap(int *a, int *b);

int swap(int *a, int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int main(int argc, char *argv[])
{
    int a = 10;
	int b = 20;
	printf("a = %d, b = %d\n", a , b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a , b);
    return 0;
}

