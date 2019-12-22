#include <stdio.h>

int main(void)
{
    int *p = NULL;
	int a = 10;
	p = &a;
    if (p != NULL)
	{
		printf("value is %d", *p);
	}
	else
	{
		printf("not assign point");
	}

    return 0;
}

