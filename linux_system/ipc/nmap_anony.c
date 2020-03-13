#include "hyzc.h"
#include <sys/mman.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
    int res, *p;
	pid_t pid;

	p = (int *)mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED){
		perror("mmap error\n");
		exit(1);
	}
	pid = fork();
	sys_err(pid, "fork error\n", 1);

	if(pid == 0){
		*p = 10;
	}
    else{	
		sleep(1);
		printf("resut:%d\n", *p);
		wait(NULL);
	}
	
	res = munmap(p, 4);
	sys_err(res, "munmap error\n", 2);


	return 0;
}
