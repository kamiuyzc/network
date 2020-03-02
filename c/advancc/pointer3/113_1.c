#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[][3] = {1, 2, 3, 4, 5, 6};
	int (*p)[3];
	p = a;
	printf("%p\n", p);
	printf("%p\n", p + 1);
	int i, j;
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 3;j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
    int t[10];
	printf("t &t %d %d\n", sizeof(t), sizeof(&t));
	printf("a &a %d %d\n", sizeof(a), sizeof(&a));
	printf("a[0] &a[0] %d %d\n", sizeof(a[0]), sizeof(&a[0]));
	printf("*(a + 0) &*(a + 0) %d %d\n", sizeof(a[0]), sizeof(&a[0]));
    return 0;
}

