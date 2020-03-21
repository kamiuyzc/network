#include "hyzc.h"

int main(int args, char *argv[])
{
	int fd = open("1.txt", O_RDWR | O_CREAT, 0755);
	sys_err(fd, "open", 1);
	printf("ttyname 0 %s\n", ttyname(0));
	printf("ttyname 1 %s\n", ttyname(1));
	printf("ttyname 2 %s\n", ttyname(2));
	printf("ttyname 3 %s\n", ttyname(3));
	return 0;
}
