#include <stdio.h>

int main(void)
{
	char buf[10];
	printf("Please input somethine:\n");
    fgets(buf, sizeof(buf), stdin);
    printf("$result is :%s$\n", buf);
    return 0;
}

