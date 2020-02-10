#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persion
{
	char name[50];
	int age;
};
int main(void)
{
	struct Persion a1[] = {"yzc1", 20, "abc1", 30};
	struct Persion a2[] = {
		{"yzc2", 40}, 
		{"abc2", 50}
	};
	int i;
	for(i = 0;i < 2;i++)
	{
       printf("%s %d\n",a1[i].name, a1[i].age); 
	}
	for(i = 0;i < 2;i++)
	{	
       printf("%s %d\n",a2[i].name, a2[i].age); 
	}
    
    struct Persion *p3 = (struct Persion *)malloc(sizeof(struct Persion) * 3);
    for(i = 0;i < 3;i++)	
	{
		sprintf(p3[i].name, "teacher_%d", i);
	}


    for(i = 0;i < 3;i++)	
	{
		printf("%s\n", p3[i].name);
	}
	return 0;
}

