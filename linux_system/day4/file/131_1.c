#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	int flags;
    flags = fcntl(STDIN_FILENO, F_GETFL);
	printf("flags: %o\n", flags);
    printf("flags: %o\n", O_NONBLOCK);	
	flags |= O_NONBLOCK;
	printf("flags: %o\n", flags);
    flags = fcntl(STDIN_FILENO, F_SETFL, flags);
	return 0;
}

