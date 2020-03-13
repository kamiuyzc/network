#include "hyzc.h"
#include <sys/mman.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
    int a = 100;
    int fd, res, len; 
	int *p = NULL;
	pid_t pid;

	fd = open("1.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
    sys_err(fd, "open error\n", 1);

	res = ftruncate(fd, 4);
    sys_err(res, "truncate error\n", 2);
	len = lseek(fd, 0, SEEK_END);
	printf("len:%d\n", len);

	p = (int *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if(p == MAP_FAILED ){
		perror("mmap error\n");
		exit(3);
	}

	close(fd);

	pid = fork();
	sys_err(pid, "fork error\n", 3);
	
	if(pid == 0){
	    *p = 1000; 	
	    a = 300;
		printf("child result:p %d\n", *p);
		printf("child result:a %d\n", a);
	}
    else{	
		sleep(1);
		printf("father result:p %d\n", *p);
		printf("father result:a %d\n", a);
		wait(NULL);
	}

    res = munmap(p, len);
	sys_err(res, "mumap error\n", 4);

	return 0;
}

