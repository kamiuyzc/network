#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>



int main(int args, char *argv[])
{
	char *src = (char *)malloc(sizeof(argv[1]) * sizeof(char *));
	char *dst = (char *)malloc(sizeof(argv[2]) * sizeof(char *));
	FILE *fds, *fdw;
	src = argv[1];
	dst = argv[2];

	fds = fopen(src, "r");
    fdw = fopen(dst, "w");
    
	char c;

	while(!feof(fds))
	{
		c = fgetc(fds);
		if(c != -1)
		{
		    fputc(c, fdw);
		}
	}

	fclose(fds);
	fclose(fdw);
	return 0;
}
