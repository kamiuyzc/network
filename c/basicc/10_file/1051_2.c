#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char a[100];
	char *b = (char *)malloc(1024);
	int len = 0;
	int slen = 0;
    while(1) 
	{
		fgets(a, 100, stdin);
		if (strcmp(a, ":wq\n") == 0)
		{
			FILE *fp = fopen(argv[1],"w");
			fwrite(b, 1, len, fp);
			break;
		}
	    slen = strlen(a); 	
        strncpy(b + len, a, slen);
		len = slen + len;
	}
	return 0;
}

