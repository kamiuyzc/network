#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int args, char *argv[])
{
	int fd, n, i;
	char buf[1024] = {0};
	fd = open("/dev/tty", O_NONBLOCK | O_RDWR); 
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}
	for(i = 0;i < 5;i++)
	{
		n = read(fd, buf, 1024);	
		if(n == -1)
		{
			if(errno == EAGAIN || errno == EWOULDBLOCK)
			{
				printf("error when device/network file read by non block and no data\n");
				sleep(2);
			}
			else
			{
				printf("read error");
			}
		}
		else
		{
			printf("re: %s\n", buf);
			break;
		}
		
	}
	close(fd);


	return 0;
}

