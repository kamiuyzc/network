#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_array(int *array, int n)
{
   srand((unsigned int)time(NULL)); 
   for(int i = 0; i < n;i++)
   {
	   array[i] = rand()%100;
   }
}

void sort_array(int *array, int n)
{
	int tmp;
    for(int i = 0;i < n - 1;i++)
	{
		for(int j = i + 1;j < n;j++)
		{
		    if (array[i] > array[j])
			{
                tmp = array[i];
				array[i] = array[j];
				array[j] = tmp; 
			}
		}
	}
}

void print_array(int *array, int n)
{
   for(int i = 0; i < n;i++)
   {
	   printf("%d\n", array[i]);
   }
}	
int main(void)
{
	int a[10];
	gen_array(a, 10 );
	printf("before\n");
	print_array(a, 10);
    sort_array(a, 10);
	printf("after\n");
	print_array(a, 10);
	return 0;
}

