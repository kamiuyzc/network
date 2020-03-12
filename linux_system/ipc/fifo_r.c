#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd, i;
	char buf[1024] = {0};

	fd = open("mymkfifo", O_RDWR);
	sys_err(fd, "open error\n", 2);
    i = 0;
	while(1){
		memset(buf, 0, 1024);
		read(fd, buf, 1024);
		printf("%s",buf);
		sleep(5);
	}
    close(fd);
	return 0;
}

