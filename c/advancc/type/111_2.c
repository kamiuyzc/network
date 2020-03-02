#include <stdio.h>
#include <stdlib.h>

char *get_str1()
{
	char *p = "hello data";
	return p;
}

char *get_str2()
{
	char p[] = "hello stati";
	return p;
}

char *get_str3()
{
    char *q = (char *)malloc(50);
	q = "hello heap";
	return q;
}
int main(void)
{
    char *q = get_str1();
	printf("data zone%s\n", q);
	
    char *q2 = get_str2();
	//printf("stack zone%s\n", q2);

    char *q3 = get_str3();
	printf("heap zone%s\n", q3);
	return 0;
}

