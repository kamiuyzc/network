#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
	unsigned int tm = (unsigned int)time(NULL);
	printf("time is %d\n", tm);
    srand(tm);

    i = rand();
    printf("%d\n", i);
    return 0;
}

