#include "hyzc.h"
#include <sys/mman.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
    int fd, res, *p;
	pid_t pid;

	fd = open("/dev/zero", O_RDWR, 0755);
    p = (int *)mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED){
		perror("map error\n");
		exit(1);
	}

	pid = fork();
	sys_err(pid, "fork error\n", 2);
	if(pid == 0){
		*p = 40;
	}
	else{
		sleep(1);
		printf("result:%d\n", *p);
		wait(NULL);
	}
	res = munmap(p, 4);
	sys_err(res, "munmap error\n", 3);
	return 0;
}

