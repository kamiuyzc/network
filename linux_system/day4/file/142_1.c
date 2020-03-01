#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    struct stat st;
	stat(argv[1], &st);
	printf("%o, %o\n", st.st_mode & S_IFMT, S_IFCHR);
    //#.st_mode & S_IFMT
	return 0;
}

