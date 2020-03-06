#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    struct stat st;
	lstat(argv[1], &st);
	if(S_ISREG(st.st_mode))
	{
		printf("is file");
	}
	else if(S_ISDIR(st.st_mode))
	{
		printf("is dir");
	}
	else if(S_ISBLK(st.st_mode))
	{
		printf("is block");
	}
	else if(S_ISCHR(st.st_mode))
	{
		printf("is char");
	}
	else if(S_ISSOCK(st.st_mode))
	{
		printf("is sock");
	}
	else if(S_ISFIFO(st.st_mode))
	{
		printf("is fifo");
	}
	else if (S_ISLNK(st.st_mode))
	{
		printf("is link");
	}
	else if (S_ISLNK(st.st_mode))
	{
		printf("other");
	}
	printf("%o, %o\n", st.st_mode & S_IFMT, S_IFCHR);
	return 0;
}

