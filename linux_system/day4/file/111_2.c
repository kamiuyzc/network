#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	char *src = (char *)malloc(sizeof(argv[1]) * sizeof(char *));
	char *dst = (char *)malloc(sizeof(argv[2]) * sizeof(char *));
	int fds, fdw;
	src = argv[1];
	dst = argv[2];

	fds = open(src, O_RDONLY);
    fdw = open(dst, O_CREAT | O_WRONLY, 0755);
	if(fds == -1 || fdw == -1)
	{
        printf("%d %s\n", errno, strerror(errno));
		perror("open error: ");
		exit(1);
	}
    
	char buf[1024];
	int n;
	while((n = read(fds, buf, 1)))
	{
		write(fdw, buf, n);
		memset(buf, 0, 1);
	}
	close(fds);
	close(fdw);
	return 0;
}
