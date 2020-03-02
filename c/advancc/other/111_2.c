#include <stdio.h>

#define PI 3.14

#define SQ(r)  PI  *  (r)  * (r)

#define MAX(a, b)  a > b ? a : b

#define MAX3(a, b, c)  (MAX(a, b)) > (c) ? (MAX(a, b)) : c

int main(void)
{
    printf("%f\n", PI); 
    printf("%f\n", SQ(1 + 1)); 
	int a = 2;
	int b = 3;
	//printf("%d\n", a < b ? a: b);
	printf("%d\n", MAX(6 + 3, 7));
	printf("%d\n", MAX3(11, 12, 10));

	return 0;
}

