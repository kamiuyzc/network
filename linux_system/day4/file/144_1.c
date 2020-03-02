#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

int main(int args, char *argv[])
{
	char *dirname = argv[1];
	DIR *dp;
    dp = opendir(dirname);

	struct dirent *sdp;
	errno = 0;
	char c = '.';
	while((sdp = readdir(dp)) != NULL)
	{
		if(c != (sdp -> d_name)[0])
		printf("%s\t", sdp -> d_name);
	}
	printf("\n");
		
	closedir(dp);
	return 0;
}

