#include "random.h" 

void print_array(int *a, int n)
{
    for(int i = 0;i < 10;i++)
	{
		printf("%d\n", a[i]);
	}
}

void select_array(int *a, int n)
{
    int i, j, tmp;
	for(i = 0;i < n - 1;i++)
	{
		for(j = i + 1;j < n;j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

}

void select_bubble(int *a, int n)
{
    int i, j, tmp;
	for(i = 0;i < n - 1;i++)
	{
		for(j = 0;j < n - 1;j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

}
int main(void)
{
	int a[10] = {0};
	get_radom_array(a, 10);
	print_array(a, 10);
	select_bubble(a, 10);
	printf("\n");
	print_array(a, 10);
	return 0;
}
