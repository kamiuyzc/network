#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd, i, n;
	char buf[1024] = {0};

    fd = open("mymkfifo", O_RDWR);
    sys_err(fd, "open error\n", 1);
    i = 0;
	while(1){
		memset(buf, 0, 1024);
		sprintf(buf, "info %d\n", i++);
		n = write(fd, buf, strlen(buf));
        sys_err(n, "write error\n", 1);
		sleep(1);
	}

	close(fd);
	return 0;
}

