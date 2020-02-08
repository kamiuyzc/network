#include <stdio.h>

int main(int argc, char *argv[])
{
    int a1[][3] = {1, 2, 3, 4, 5, 6}; 
	int i,j;
	printf("a1   %p\na1+1 %p\n", a1, a1 + 1);
	for(i = 0;i < 2;i++)
	{
		for(j = 0;j < 3;j++)
		{
			printf("%d ", a1[i][j]);
			printf("%d ", *(*(a1 + i) + j));
		}
		printf("\n");

    return 0;
}

