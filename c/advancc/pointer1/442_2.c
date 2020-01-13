#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[100] = "hello12345haha";
    int b = 0;	
    sscanf(a, "%*[a-z]%dhaha", &b);
	printf("%d\n", b);

    char a1[100] = "123456aaaabb";
	char c[10] = {0};
	sscanf(a1, "%*d%s", c);
	printf("%s\n", c);

	memset(c, 0 ,10);
	memset(a, 0, 100);
	strcpy(a, "123456aaa");
	sscanf(a, "%7s", c);
	printf("%s\n", c);


	memset(c, 0 ,10);
	memset(a, 0, 100);
	strcpy(a, "1abcdefg123456");
	sscanf(a, "%*d%[a-z]", c);
	printf("%s\n", c);
	
	memset(c, 0 ,10);
	memset(a, 0, 100);
	strcpy(a, "zabcdefg123456");
	sscanf(a, "%[abz]", c);
	printf("%s\n", c);

	memset(c, 0 ,10);
	memset(a, 0, 100);
	strcpy(a, "zcbcdefg123456");
	sscanf(a, "%[^a]", c);
	printf("%s\n", c);
	return 0;
}

