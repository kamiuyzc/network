#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Persion
{
	char *name;
	int age;
};

void allocate_memory(struct Persion **p)
{
   struct Persion *tmp = (struct Persion *)malloc(sizeof(struct Persion)); 
   tmp -> age = 30;
   tmp -> name = (char *)malloc(60 * sizeof(char));
   strcpy(tmp -> name, "abc");
   *p = tmp;
}

void print_persion(struct Persion *p)
{
    printf("%s %d\n", p -> name, p -> age);
}

void free_memory(struct Persion **p)
{
	struct Persion *tmp;
    tmp = *p;	
	free(tmp -> name);
	tmp -> name = NULL;
	free(tmp);
    *p = NULL;
}

int main(void)
{
    struct Persion *p = NULL;
	allocate_memory(&p);
	print_persion(p);
	free_memory(&p);
	return 0;
}

