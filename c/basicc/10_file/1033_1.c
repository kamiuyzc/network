#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "w");
    int n = 3;
	int ret;
	for (int i = 0; i < n;i++)
	{
		ret = fprintf(fp, "cmd %d \n", i);
		printf("%d", ret);
	}
    return 0;
}

