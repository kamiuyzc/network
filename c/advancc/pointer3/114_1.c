#include <stdio.h>

typedef int (*P)[3];

void print_array(int q[][3])
{
	int i, j;
	for(i = 0;i < 2;i++)	
	{
		for(j = 0;j < 3;j++)
		{
			printf("%d ", *(*(q + i) + j));
		}
		printf("\n");
	}
}

void print_array2(int (*q)[3])
{   
	int i, j;
	for(i = 0;i < 2;i++)
	{   
		for(j = 0;j < 3;j++)
		{
			printf("%d ", *(*(q + i) + j));
		}
		printf("\n");
	}
}

void print_array3(P q)
{   
	int i, j;
	for(i = 0;i < 2;i++)
	{   
		for(j = 0;j < 3;j++)
		{
			printf("%d ", *(*(q + i) + j));
		}
		printf("\n");
	}
}
int main(int argc, char *argv[])
{
	int a[][3] = {1, 2, 3, 4, 5, 6}; 
	P p;
	p = a;
	print_array3(p);
	return 0;
}

