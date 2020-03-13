#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd, res;
	char buf[1024];
	char *str1 = "write in out2\n";
	sleep(2);

	fd = open("1.out", O_RDWR);
	sys_err(fd, "open error\n", 1);

	res = read(fd, buf, 1024);
	sys_err(res ,"read error\n", 2);
	printf("%s\n", buf);

	res = write(fd, str1, strlen(str1));

    close(fd);
	return 0;
}

