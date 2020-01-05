#include <stdio.h>
#include <string.h>

struct student
{
   int n;
   char name[10];
   float score;
};
int main(void)
{
    struct student std1[3] = 
	{
		{1, "test", 50},
		{2, "test1", 70},
		{3, "test2", 80},
	};
    for(int i = 0; i < 3; i++)
	{
		printf("%d %s %.2f\n", std1[i].n, std1[i].name, std1[i].score);
	}
	return 0;
}

