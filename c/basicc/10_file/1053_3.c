#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void write_file()
{
	srand((unsigned int)time(NULL));
	char  a[1024 *4] = {0};
	int i;
	char t[100]  = {0};
	for(i = 0;i < 5;i++)
	{
		sprintf(t, "%d\n", rand()%100);
		strcat(a, t);
	}
	FILE *fp = fopen("1.out", "w");
	fputs(a, fp);
	fclose(fp);
}

void read_file()
{
	FILE *fp = fopen("1.out", "r");
	int a[1024];
	char tmp[100];
	int n;
	int nums = 0;
	while(1)
	{
		int ret = fgets(tmp, 100, fp); 
		if (feof(fp))
		{
			break;
		}
		sscanf(tmp, "%d\n", &n);
		a[nums] = n;
		nums++;
	}
	fclose(fp);
	fsort(a, nums);
}


int main(int argc, char *argv[])
{
	write_file();
	read_file();
}

void fsort(int *array, int n)
{
	int tmp;
	for(int i = 0;i < n - 1;i++)     
	{
		for(int j = 0;j < n - 1 - i;j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	for(int i = 0; i < n;i++)
	{
		printf("%d\n", array[i]);
	}
}
