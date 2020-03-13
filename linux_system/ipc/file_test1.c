#include "hyzc.h"
#define NUM 5
int main(int args, char *argv[])
{
    int fd, res;
	fd = open("1.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
    sys_err(fd, "open error\n", 2);
   
	char *str1 = "write in 1.out\n";
    char buf[1024] = {0};
	res = write(fd, str1, strlen(str1));
    sys_err(fd, "res error\n", 2);

	sleep(NUM);

    res = lseek(fd, 0, SEEK_SET);
    sys_err(fd, "lseek error\n", 2);

	res = read(fd, buf, 1024);
    sys_err(fd, "read error\n", 2);

	printf("%s", buf);
	close(fd);


	return 0;
}

