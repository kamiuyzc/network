#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "hello";
	char b[] = "world";
	char s1[100];
    sprintf(s1, "%s %s!", a, b);
	printf("s1=%s", s1);

	printf("\n");
	memset(s1, 0 , 100);
	int num = 10;
    sprintf(s1, "%d", num);
	printf("%s",s1);
	printf("\n");

    sprintf(s1, "%8d", num);
	printf("%s",s1);
	printf("\n");

    sprintf(s1, "%x", num);
	printf("%s",s1);
	printf("\n");
	
    sprintf(s1, "%o", num);
	printf("%s",s1);
	printf("\n");
	return 0;
}

