#include "hyzc.h"
#include <sys/mman.h>

int main(int args, char *argv[])
{
    int fd, res;
	char *p = NULL;

	fd = open("a.out", O_RDWR | O_TRUNC | O_CREAT, 0755);

    sys_err(fd, "open error\n", 1);
	ftruncate(fd, 20);
	/*
	char a[4096] = {'a'};
	char b[4096] = {'b'};
	char c[4096] = {'c'};
	write(fd, a, 4096);
	write(fd, b, 4096);
	write(fd, c, 4096);
	*/
	int len = lseek(fd, 0, SEEK_END);
	printf("file len:%d\n", len);
    close(fd);

	fd = open("a.out", O_RDWR, 0755);
    sys_err(fd, "open error\n", 1);

	p = mmap(NULL, len, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);

	close(fd);

	if(p == MAP_FAILED){
		perror("mmap error:");
		exit(2);
	}

	
    strcpy(p, "hello world!");
    printf("%s\n", p);

    res = munmap(p, len);
	sys_err(res, "munmap error\n",2);
	return 0;
}
