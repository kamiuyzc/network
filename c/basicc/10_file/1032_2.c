#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "r"); 
	char s[7];
	memset(s, 0, sizeof(s));
	while (fgets(s, sizeof(s), fp))
	{
		printf("%s", s);
		printf("\n");
	}
    return 0;
}

