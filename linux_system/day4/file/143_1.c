#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
	char *src = argv[1];
	char *dst = argv[2];
	int n;
    n = link(src, dst);
	if(n == -1)
	{
		perror("link error");
	}

	unlink(src);
	return 0;
}

