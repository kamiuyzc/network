#include "hyzc.h"
#include <sys/signal.h>

int main(int args, char *argv[])
{
	pid_t pid;
	int res;
	pid = fork();
	sys_err(pid, "fork error\n", 1);
	if(pid > 0){
		while(1){
			printf("parent %d\n", getpid());
			sleep(1);
		}
	}
	else{
		printf("child pid = %d ppid = %d\n", getpid(), getppid());
		sleep(5);
		res = kill(0 - getppid(), SIGKILL);
		sys_err(res, "kill error\n", 2);
		while(1);
	}

	return 0;
}

