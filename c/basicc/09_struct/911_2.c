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
    struct student std1;
	std1.n = 10;
    strcpy(std1.name, "yzc");
	std1.score = 50;
	printf("%d %s %.2f", std1.n, std1.name, std1.score);
	return 0;
}

