#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp1 = fopen("1.out", "r");
	FILE *fp2 = fopen("2.out", "w");
	char a[1024 * 4] = {0};
	int len;
	while(1) 
	{
		len = fread(a, 1, sizeof(a), fp1); 
		if (len != 0)
		{
			fwrite(a, 1, len, fp2);
		}
		else
		{
			break;
		}
	}
	return 0;
}

