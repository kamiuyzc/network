#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int n, fd;
	fd = open("1.txt", O_CREAT | O_RDONLY, 0442);
	if(fd == -1)
	{
		printf("%d\n", errno);	
		printf("%s\n", strerror(errno));
	}
	n =  close(fd);
	if(n < 0)
	{
		printf("%d\n", errno);	
		printf("%s\n", strerror(errno));
	}
	return 0;
}

