#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "r"); 
	int i;
	char *s;
	int ret;
	ret = fscanf(fp, "%s %d\n", s, &i);
	printf("%d\n", ret);
	printf("%s %d\n", s, i);
	ret = fscanf(fp, "%s %d\n", s, &i);
	printf("%d\n", ret);
	printf("%s %d\n", s, i);
	ret = fscanf(fp, "%s %d\n", s, &i);
	printf("%d\n", ret);
	printf("%s %d\n", s, i);
	ret = fscanf(fp, "%s %d\n", s, &i);
	printf("%d\n", ret);
	printf("%s %d\n", s, i);
    return 0;
}

