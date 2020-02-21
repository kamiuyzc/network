#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp_r = fopen("121_4.c", "r");
	FILE *fp_w = fopen("131_4.c", "w");
	char a[128] = {0};
	int n = -1;
    while(!feof(fp_r))
	{    
	    memset(a, 0, 128);
		n = fread(a, 1, 128, fp_r);
		if(n != 0) 
		{
            fwrite(a, 1, 128, fp_w);
		}
	}
	fclose(fp_r);
	fclose(fp_w);
	return 0;
}

